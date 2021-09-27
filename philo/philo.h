/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:01:56 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 18:31:26 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/time.h>

# define THINK	0
# define EAT	1
# define SLEEP	2
# define DIED	4
# define TAKE_FORK 	5
# define DONE		6

typedef struct s_state
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		protect_write;
	pthread_t			sup;
	pthread_t			sup_d;
	int					is_dead;
	int					is_done;
	int					np;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					nb_must_eat;
	long long			time_start;
}	t_state;

typedef struct s_philo
{
	int					philo_id;
	pthread_mutex_t		is_eating;
	int					eating;
	int					times_philo_ate;
	long				last_meal;
	pthread_t			tid;
	t_state				*state;
}	t_philo;

long long	calculate_timestamp(void);
int			create_threads(t_state *state, t_philo *philo);
void		*philosopher(void *args);
void		print_state(int state, t_philo *philo);
void		take_forks(t_philo *philo);
void		start_eat(t_philo *philo);
void		go_to_sleep(t_philo *philo);
void		think(t_philo *philo);
void		*death_supervisor(void *arg);
void		*supervisor(void *arg);
int			ft_atoi(const char *str);

#endif
