/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:17:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/11 21:40:19 by zqadiri          ###   ########.fr       */
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
# define DONE		6
# define TO_MICRO	1000000

typedef struct s_state
{
	pid_t				*pid;
	int					np;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					nb_must_eat;
	long				time_start;
	sem_t				*forks;
	sem_t				*eating;
	sem_t				*write;
}	t_state;

typedef struct s_philo
{
	int		is_dead;
	int		is_done;
	int		philo_id;
	t_state	*state;
	long	last_meal;
	int		times_philo_ate;
}	t_philo;

long	calculate_timestamp(void);
void	print_state(int state, t_philo *philo);
int		get_args(t_state *state, char **args);

#endif
