/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:01:56 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/11 10:53:18 by zqadiri          ###   ########.fr       */
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
# define TO_MICRO	1000000

typedef struct s_state
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex;
	pthread_mutex_t		protect_write;
	pthread_t			sup;
	pthread_t			sup_d;
	int					is_dead;
	int					is_done;
	int					np;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					nb_must_eat;
	long				time_start;
}	t_state;

typedef struct s_philo
{
	int					philo_id;
	pthread_mutex_t		is_eating;
	int					times_philo_ate;
	long				last_meal;
	int					eating;
	pthread_t			tid;
	t_state				*state;
}	t_philo;

int			init(t_philo *philo);
void		print_args(t_state *state);
long		calculate_timestamp(void);
void		_do(long time_to_eat);
int			create_threads(t_state *state, t_philo *philo);
void		*philosopher(void *args);
void		exit_error(void);
void		print_state(int state, t_philo *philo);
void		take_forks(t_philo *philo);
void		start_eat(t_philo *philo);
void		go_to_sleep(t_philo *philo);
void		think(t_philo *philo);
void		check_death(t_philo *arg);
void		check_done(t_philo *philo);
void		detach_philo(t_philo *args);
void		*death_supervisor(void *arg);
int			ft_atoi(const char *str);

#endif
