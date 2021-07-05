/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:15:33 by smago             #+#    #+#             */
/*   Updated: 2021/01/22 20:28:18 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef	pthread_mutex_t	t_mutex;

typedef struct		s_data
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				times;
	int				fin;
	pthread_t		thread_0;
	t_mutex			*mutex;
	t_mutex			mutex_head;
	struct timeval	start;
}					t_data;

t_data g_data;

typedef struct		s_phil
{
	pthread_t		thread;
	int				num;
	int				times;
	unsigned long	time;
	unsigned long	last;
	struct s_phil	*next;
}					t_phil;

int					ft_parse(int ac, char **av);
int					ft_error(int i);
int					ft_init(t_phil **phil);
int					ft_create_mutex(void);
int					ft_check(t_phil *tmp);
int					ft_check_times_to_eat(t_phil *tmp);
void				ft_clear(t_phil *phil);
void				ft_clear_mutex(void);
unsigned long		ft_timez(void);
void				ft_lock(t_phil *tmp);
void				ft_unlock(t_phil *tmp);
void				ft_join_detach(t_phil *tmp);

#endif
