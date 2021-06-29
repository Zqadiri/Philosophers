/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:01:56 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/29 20:02:56 by zqadiri          ###   ########.fr       */
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
# define DIE	4

typedef struct s_state
{
	long		time_start;
}   t_state;

typedef struct s_philo
{
	pthread_t	*tid;
	pthread_t	sup;
	int			np;         // ! also the number of forks
	size_t		time_to_die;   
	size_t		time_to_eat;     // ! in milliseconds 
	size_t		time_to_sleep;
	int			nb_must_eat; // ! optional
}   t_philo;

typedef struct s_args
{
	int			philo_id;
	t_philo		*philo;
}	t_args;

int		init(t_philo *philo, t_state *state);
void	print_args(t_philo *philo, t_state *state);

int		create_threads(t_philo *philo);
void    *philosopher(void *args);
void    exit_error(void);

#endif
