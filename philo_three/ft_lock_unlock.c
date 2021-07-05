/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_unlock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:40:44 by smago             #+#    #+#             */
/*   Updated: 2021/01/26 17:44:10 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_unlock(void)
{
	sem_post(g_data.sem_forks);
	sem_post(g_data.sem_forks);
}

void	ft_lock(void)
{
	sem_wait(g_data.sem_pair);
	sem_wait(g_data.sem_forks);
	sem_wait(g_data.sem_forks);
	sem_post(g_data.sem_pair);
}
