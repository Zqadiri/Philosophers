/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:01:56 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/29 17:56:02 by zqadiri          ###   ########.fr       */
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

typedef struct s_state
{
	long		time_start;
	
}   t_state;

typedef struct s_philo
{
	int			np;         // ! also the number of forks
	size_t		tt_die;   
	size_t		tt_eat;     // ! in milliseconds 
	size_t		tt_sleep;
	int			nb_must_eat; // ! optional
}   t_philo;

int		init(t_philo *philo, t_state *state);
void	print_args(t_philo *philo, t_state *state);

#endif
