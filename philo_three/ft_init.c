/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:44:09 by smago             #+#    #+#             */
/*   Updated: 2021/01/28 15:49:15 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_create_semaphore(void)
{
	int i;

	i = g_data.number;
	sem_unlink("/semaphore1");
	sem_unlink("/semaphore2");
	sem_unlink("/semaphore3");
	if ((g_data.sem_forks = sem_open("/semaphore1", O_CREAT, \
				0666, i)) == SEM_FAILED)
		return (ft_error(5));
	if ((g_data.sem_pair = sem_open("/semaphore2", O_CREAT, \
				0666, 1)) == SEM_FAILED)
	{
		ft_clear_semaphore();
		return (ft_error(5));
	}
	if ((g_data.sem_head = sem_open("/semaphore3", O_CREAT, \
				0666, 1)) == SEM_FAILED)
	{
		ft_clear_semaphore();
		return (ft_error(5));
	}
	return (0);
}

int		ft_init2(t_phil **phil)
{
	t_phil	*head;
	t_phil	*tmp;
	int		i;

	i = 0;
	head = (*phil);
	while (++i < g_data.number)
	{
		if (!(tmp = malloc(sizeof(t_phil))))
		{
			ft_clear(*phil);
			return (1);
		}
		tmp->num = i + 1;
		tmp->next = NULL;
		tmp->times = g_data.times;
		tmp->last = 0;
		head->next = tmp;
		head = head->next;
	}
	return (0);
}

int		ft_init(t_phil **phil)
{
	if (!((*phil) = malloc(sizeof(t_phil))))
		return (ft_error(4));
	(*phil)->num = 1;
	(*phil)->next = NULL;
	(*phil)->times = g_data.times;
	(*phil)->last = 0;
	if (ft_init2(phil))
		return (ft_error(4));
	return (0);
}
