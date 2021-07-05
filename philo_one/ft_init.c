/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:44:09 by smago             #+#    #+#             */
/*   Updated: 2021/01/22 17:43:29 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_create_mutex(void)
{
	int i;

	i = 0;
	if (!(g_data.mutex = malloc(sizeof(t_mutex) * g_data.number)))
		return (ft_error(4));
	while (i < g_data.number)
	{
		if (pthread_mutex_init(&g_data.mutex[i], NULL))
			return (ft_error(5));
		i++;
	}
	pthread_mutex_init(&g_data.mutex_head, NULL);
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
