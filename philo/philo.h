/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:01:56 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 17:31:55 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/time.h>
# include "../libft/libft.h"

# define THINK	0
# define EAT	1
# define SLEEP	2
# define DIED	4
# define TAKE_FORK 	5
# define DONE		6
# define TO_MICRO	1000000

typedef struct s_philo
{
	int					is_dead;
	int					is_done;
	int					eating;
	pthread_t			*tid;
	pthread_t			sup;
	pthread_mutex_t		is_eating;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex;
	pthread_mutex_t		protect_write;		// ! synchronize access to memory
	int					np;         		// ! also the number of forks
	int					time_to_die;   
	int					time_to_eat;     	// ! in milliseconds 
	int					time_to_sleep;
	int					nb_must_eat; 		// ! optional
	int					*times_philo_ate;
	long				*timestamp;
	long				death_time;
	int					time_start;
	pthread_t			sup_d;
}   t_philo;

typedef struct s_args
{
	int			philo_id;
	t_philo		*philo;
}	t_args;

int			init(t_philo *philo);
void		print_args(t_philo *philo);
long long	calculate_timestamp(void);
int			create_threads(t_philo *philo);
void		*philosopher(void *args);
void		exit_error(void);
void		print_state(int state, t_args *data);
void		take_forks(t_args *data);
void		start_eat(t_args *data);
void		go_to_sleep(t_args *data);
void		think(t_args *data);
void		_do(size_t time_to_eat);
void		check_death(t_args *arg);
void		check_done(t_args *arg);
void		detach_philo(t_args *args);
void    	*death_supervisor(void *arg);

#endif
