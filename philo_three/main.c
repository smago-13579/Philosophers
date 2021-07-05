/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:20:25 by smago             #+#    #+#             */
/*   Updated: 2021/01/28 17:22:16 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_take_fork(t_phil *tmp)
{
	ft_lock();
	sem_wait(g_data.sem_head);
	tmp->time = ft_timez();
	tmp->last = tmp->time;
	printf("%ldms %d has taken a fork\n", ft_timez(), tmp->num);
	printf("%ldms %d has taken a fork\n", ft_timez(), tmp->num);
	printf("%ldms %d is eating\n", ft_timez(), tmp->num);
	sem_post(g_data.sem_head);
	while (ft_timez() - tmp->time < (unsigned long)g_data.eat)
		usleep(1);
	ft_unlock();
	return (0);
}

void	*ft_dinner(t_phil *tmp)
{
	if (pthread_create(&(tmp->thread), NULL, ft_check, tmp))
	{
		ft_error(6);
		exit(1);
	}
	while (tmp->times > 0)
	{
		if (ft_take_fork(tmp))
			return (NULL);
		sem_wait(g_data.sem_head);
		tmp->time = ft_timez();
		printf("%ldms %d is sleeping\n", ft_timez(), tmp->num);
		sem_post(g_data.sem_head);
		while (ft_timez() - tmp->time < (unsigned long)g_data.sleep)
			usleep(1);
		sem_wait(g_data.sem_head);
		tmp->time = ft_timez();
		printf("%ldms %d is thinking\n", ft_timez(), tmp->num);
		sem_post(g_data.sem_head);
		tmp->times--;
	}
	pthread_join(tmp->thread, NULL);
	exit(0);
}

void	ft_set_order(t_phil *tmp)
{
	while (tmp)
	{
		tmp->pid = fork();
		if (tmp->pid < 0)
		{
			ft_clear_semaphore();
			ft_clear(tmp);
			ft_error(7);
			exit(1);
		}
		else if (tmp->pid == 0)
		{
			ft_dinner(tmp);
		}
		else
			tmp = tmp->next;
	}
}

void	*ft_start(void *arg)
{
	t_phil	*tmp;
	int		status;

	tmp = (t_phil *)arg;
	gettimeofday(&(g_data.start), NULL);
	ft_set_order(tmp);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		while (tmp)
		{
			waitpid(tmp->pid, NULL, 0);
			tmp = tmp->next;
		}
	}
	else
		kill(0, SIGKILL);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_phil			*phil;

	if (ft_parse(ac, av))
		return (1);
	if ((ft_init(&phil)))
		return (1);
	if (ft_create_semaphore())
	{
		ft_clear(phil);
		return (1);
	}
	if (pthread_create(&(g_data.thread_0), NULL, ft_start, phil))
	{
		ft_clear_semaphore();
		ft_clear(phil);
		return (ft_error(6));
	}
	pthread_join(g_data.thread_0, NULL);
	pthread_detach(g_data.thread_0);
	ft_clear_semaphore();
	ft_clear(phil);
	exit(0);
}
