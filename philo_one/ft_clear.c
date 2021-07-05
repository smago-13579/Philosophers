/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:00:12 by smago             #+#    #+#             */
/*   Updated: 2021/01/20 16:34:25 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_clear_mutex(void)
{
	int i;

	i = 0;
	while (i < g_data.number)
	{
		pthread_mutex_destroy(&g_data.mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&g_data.mutex_head);
	free(g_data.mutex);
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
