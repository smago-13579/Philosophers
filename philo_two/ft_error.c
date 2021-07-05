/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:23:45 by smago             #+#    #+#             */
/*   Updated: 2021/01/26 16:12:45 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		ft_error(int i)
{
	(i == 1) ? printf("Wrong number of arguments\n") : 0;
	(i == 2) ? printf("Invalid argument\n") : 0;
	(i == 3) ? printf("The number of times to eat is incorrect\n") : 0;
	(i == 4) ? printf("Can't allocate memory\n") : 0;
	(i == 5) ? printf("Can't initialize semaphore\n") : 0;
	(i == 6) ? printf("Can't create thread\n") : 0;
	return (1);
}
