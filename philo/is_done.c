/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:48 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/18 10:31:17 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach_philo(t_philo *args)
{
	int		i;

	i = 0;
	while (i < args->state->np)
	{
		pthread_detach(args[i].tid);
		i++;
	}
	pthread_detach(args->state->sup);
	pthread_detach(args->state->sup_d);
	i = 0;
	while (i < args->state->np)
	{
		pthread_mutex_destroy(&(args->state->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(args->is_eating));
	pthread_mutex_destroy(&(args->state->mutex));
	pthread_mutex_destroy(&(args->state->protect_write));
}

int	all_philo_are_done(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->state->np)
	{
		if (philo[i].times_philo_ate < philo->state->nb_must_eat)
			return (0);
		i++;
	}
	philo->state->is_done = 1;
	return (1);
}

void	check_done(t_philo	*philo)
{
	int		done;

	done = 0;
	if (philo->state->nb_must_eat != -1)
	{
		while (!done)
		{
			pthread_mutex_lock(&(philo->state->protect_write));
			done = all_philo_are_done(philo);
			pthread_mutex_unlock(&(philo->state->protect_write));
		}
	}
}
