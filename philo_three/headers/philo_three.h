/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:15:33 by smago             #+#    #+#             */
/*   Updated: 2021/01/28 13:53:57 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

typedef struct		s_data
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				times;
	int				fin;
	pthread_t		thread_0;
	sem_t			*sem_forks;
	sem_t			*sem_pair;
	sem_t			*sem_head;
	struct timeval	start;
}					t_data;

t_data g_data;

typedef struct		s_phil
{
	pthread_t		thread;
	pid_t			pid;
	int				num;
	int				times;
	unsigned long	time;
	unsigned long	last;
	struct s_phil	*next;
}					t_phil;

int					ft_parse(int ac, char **av);
int					ft_error(int i);
int					ft_init(t_phil **phil);
int					ft_create_semaphore(void);
void				*ft_check(void *arg);
int					ft_check_times_to_eat(t_phil *tmp);
void				ft_clear(t_phil *phil);
void				ft_clear_semaphore(void);
unsigned long		ft_timez(void);
void				ft_lock(void);
void				ft_unlock(void);
void				ft_join_detach(t_phil *tmp);

#endif
