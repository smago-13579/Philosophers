/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_unlock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:40:44 by smago             #+#    #+#             */
/*   Updated: 2021/01/22 17:23:09 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_unlock(t_phil *tmp)
{
	if (tmp->next == NULL)
		pthread_mutex_unlock(&g_data.mutex[0]);
	else
		pthread_mutex_unlock(&g_data.mutex[tmp->num]);
	pthread_mutex_unlock(&g_data.mutex[tmp->num - 1]);
}

void	ft_lock(t_phil *tmp)
{
	if (tmp->next == NULL)
		pthread_mutex_lock(&g_data.mutex[0]);
	else
		pthread_mutex_lock(&g_data.mutex[tmp->num]);
	pthread_mutex_lock(&g_data.mutex[tmp->num - 1]);
}
