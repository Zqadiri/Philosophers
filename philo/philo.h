/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:01:56 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/08 16:53:41 by zqadiri          ###   ########.fr       */
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


typedef	struct s_state
{
	//* mutex
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex;
	pthread_mutex_t		is_eating;
	pthread_mutex_t		protect_write;		// ! synchronize access to memory
	// * threads
	pthread_t			sup;
	pthread_t			sup_d;
	//* info
	int					is_dead;
	int					is_done;
	int					np;	        		// ! also the number of forks
	int					time_to_die;   
	int					time_to_eat;     	// ! in milliseconds 
	int					time_to_sleep;
	int					nb_must_eat; 
	long				time_start;
}	t_state;

typedef struct s_philo
{
	// ! optional
	int					philo_id;
	int					times_philo_ate;
	long				last_meal;
	int					eating;
	pthread_t			tid;
	t_state				*state;
}   t_philo;

int			init(t_philo *philo);
void		print_args(t_state *state);
long long	calculate_timestamp(void);


int			create_threads(t_state *state, t_philo *philo);
// void		*philosopher(void *args);
void		exit_error(void);
void		print_state(int state, t_philo *philo);
void		take_forks(t_philo *philo);
void		start_eat(t_philo *philo);
void		go_to_sleep(t_philo *philo);
void		think(t_philo *philo);
// void		_do(size_t time_to_eat);
// void		check_death(t_args *arg);
// void		check_done(t_args *arg);
// void		detach_philo(t_args *args);
void    	*death_supervisor(void *arg);

#endif
