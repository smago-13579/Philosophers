/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:00:12 by smago             #+#    #+#             */
/*   Updated: 2021/01/28 17:00:19 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_clear_semaphore(void)
{
	sem_close(g_data.sem_head);
	sem_close(g_data.sem_forks);
	sem_close(g_data.sem_pair);
	sem_unlink("/semaphore1");
	sem_unlink("/semaphore2");
	sem_unlink("/semaphore3");
}

void	ft_clear(t_phil *phil)
{
	t_phil *tmp;

	tmp = phil;
	while (tmp)
	{
		tmp = tmp->next;
		free(phil);
		phil = tmp;
	}
}
