/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:17:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 19:35:30 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <string.h>
# include <semaphore.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h> 

# define THINK	0
# define EAT	1
# define SLEEP	2
# define DIED	4
# define TAKE_FORK 	5

typedef struct s_state
{
	int					np;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			last_meal;
	int					nb_must_eat;
	int					times_philo_ate;
}	t_state;

typedef struct s_philo
{
	int					philo_id;
	long long			time_start;
	sem_t				*forks;
	sem_t				*eating;
	sem_t				*write;
	t_state				*state;
}	t_philo;

/*
** Parse
*/

int		store_args(t_state *state, char **args);
int		is_valid_args(t_state *state, char *argv[]);

/*
** Main
*/

long	calculate_timestamp(void);
void	display_state(int state, t_philo *philo);
#endif
