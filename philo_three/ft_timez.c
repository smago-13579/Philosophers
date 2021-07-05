/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timez.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:09:05 by smago             #+#    #+#             */
/*   Updated: 2021/01/28 14:12:36 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			ft_join_detach(t_phil *tmp)
{
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		pthread_detach(tmp->thread);
		tmp = tmp->next;
	}
}

int				ft_check_times_to_eat(t_phil *tmp)
{
	while (tmp)
	{
		if (tmp->times)
			return (1);
		tmp = tmp->next;
	}
	g_data.fin = 0;
	return (0);
}

void			*ft_check(void *arg)
{
	t_phil *tmp;

	tmp = (t_phil *)arg;
	while (g_data.fin && tmp->times)
	{
		sem_wait(g_data.sem_head);
		if (ft_timez() - tmp->last > (unsigned long)g_data.die)
		{
			g_data.fin = 0;
			printf("%ldms %d died\n", ft_timez(), tmp->num);
			exit(1);
		}
		sem_post(g_data.sem_head);
	}
	exit(0);
}

unsigned long	ft_timez(void)
{
	struct timeval	end;
	unsigned long	clock;

	gettimeofday(&end, NULL);
	clock = ((end.tv_sec - g_data.start.tv_sec) * 1000 + \
				(end.tv_usec - g_data.start.tv_usec) / 1000);
	return (clock);
}
