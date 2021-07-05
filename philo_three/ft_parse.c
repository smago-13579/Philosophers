/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:54:27 by smago             #+#    #+#             */
/*   Updated: 2021/01/26 17:44:12 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		put_args(char *str)
{
	int i;
	int n;

	i = 0;
	n = 10;
	while (*str >= '0' && *str <= '9')
	{
		i = i * n + (int)(*str - 48);
		str++;
	}
	if (*str)
		return (-1);
	return (i);
}

int		ft_parse(int ac, char **av)
{
	if (ac < 2 || (ac != 5 && ac != 6))
		return (ft_error(1));
	g_data.number = put_args(&av[1][0]);
	g_data.die = put_args(&av[2][0]);
	g_data.eat = put_args(&av[3][0]);
	g_data.sleep = put_args(&av[4][0]);
	g_data.fin = 1;
	if (g_data.number < 2 || g_data.die < 1 || g_data.eat < 1 || \
			g_data.sleep < 1)
		return (ft_error(2));
	g_data.times = 2147483647;
	if (ac == 6 && (g_data.times = put_args(&av[5][0])) <= 0)
		return (ft_error(3));
	return (0);
}
