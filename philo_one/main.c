/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:20:25 by smago             #+#    #+#             */
/*   Updated: 2021/01/28 17:32:51 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_take_fork(t_phil *tmp)
{
	ft_lock(tmp);
	if (!g_data.fin)
	{
		ft_unlock(tmp);
		return (1);
	}
	pthread_mutex_lock(&g_data.mutex_head);
	tmp->time = ft_timez();
	tmp->last = tmp->time;
	if (g_data.fin)
	{
		printf("%ldms %d has taken a fork\n", ft_timez(), tmp->num);
		printf("%ldms %d has taken a fork\n", ft_timez(), tmp->num);
		printf("%ldms %d is eating\n", ft_timez(), tmp->num);
	}
	pthread_mutex_unlock(&g_data.mutex_head);
	while (ft_timez() - tmp->time < (unsigned long)g_data.eat)
		usleep(1);
	ft_unlock(tmp);
	return (0);
}

void	*ft_dinner(void *arg)
{
	t_phil	*tmp;

	tmp = (t_phil *)arg;
	while (g_data.fin && tmp->times > 0)
	{
		if (ft_take_fork(tmp))
			return (NULL);
		pthread_mutex_lock(&g_data.mutex_head);
		tmp->time = ft_timez();
		if (g_data.fin)
			printf("%ldms %d is sleeping\n", ft_timez(), tmp->num);
		pthread_mutex_unlock(&g_data.mutex_head);
		while (ft_timez() - tmp->time < (unsigned long)g_data.sleep)
			usleep(1);
		pthread_mutex_lock(&g_data.mutex_head);
		tmp->time = ft_timez();
		if (g_data.fin)
			printf("%ldms %d is thinking\n", ft_timez(), tmp->num);
		pthread_mutex_unlock(&g_data.mutex_head);
		tmp->times--;
	}
	return (NULL);
}

void	ft_set_order(t_phil *phil)
{
	t_phil *tmp;

	tmp = phil;
	while (tmp)
	{
		if (tmp->num % 2 == 1)
			pthread_create(&tmp->thread, NULL, ft_dinner, tmp);
		usleep(100);
		tmp = tmp->next;
	}
	tmp = phil;
	while (tmp)
	{
		if (tmp->num % 2 == 0)
			pthread_create(&tmp->thread, NULL, ft_dinner, tmp);
		usleep(100);
		tmp = tmp->next;
	}
}

void	*ft_start(void *arg)
{
	t_phil *phil;
	t_phil *tmp;

	phil = (t_phil *)arg;
	tmp = phil;
	gettimeofday(&(g_data.start), NULL);
	ft_set_order(tmp);
	while (g_data.fin)
	{
		pthread_mutex_lock(&g_data.mutex_head);
		while (tmp && g_data.fin)
		{
			if (tmp->times)
				ft_check(tmp);
			tmp = tmp->next;
		}
		pthread_mutex_unlock(&g_data.mutex_head);
		tmp = phil;
		ft_check_times_to_eat(tmp);
	}
	tmp = phil;
	ft_join_detach(tmp);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_phil			*phil;

	if (ft_parse(ac, av))
		return (1);
	if ((ft_init(&phil)))
		return (1);
	if (ft_create_mutex())
	{
		ft_clear(phil);
		return (1);
	}
	if (pthread_create(&(g_data.thread_0), NULL, ft_start, phil))
	{
		ft_clear_mutex();
		ft_clear(phil);
		return (ft_error(6));
	}
	pthread_join(g_data.thread_0, NULL);
	pthread_detach(g_data.thread_0);
	ft_clear_mutex();
	ft_clear(phil);
	return (0);
}
