/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:48 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 11:14:01 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	detach_philo(t_args *args)
{
	int		i;

	i = 0;
	while(i < args->philo->np)
	{
		pthread_detach(args->philo->tid[i]);
		i++;
	}
	pthread_detach(args->philo->sup);
	i = 0;
	while (i < args->philo->np)
	{
		pthread_mutex_destroy(&(args->philo->is_eating[i]));
		pthread_mutex_destroy(&(args->philo->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(args->philo->mutex));
	pthread_mutex_destroy(&(args->philo->protect_write));
}

int	all_philo_are_done(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->np)
	{
		if (philo->times_philo_ate[i] < philo->nb_must_eat)
			return (0);
		i++;
	}
	philo->is_done = 1;
	return (1);
}

void	check_done(t_args	*arg)
{
	int		done;

	done  = 0;
	if (arg->philo->nb_must_eat != -1)
	{
		while (!done)
		{
			usleep(arg->philo->time_to_eat * 1000);
			pthread_mutex_lock(&(arg->philo->protect_write));
			done =	all_philo_are_done(arg->philo);
			pthread_mutex_unlock(&(arg->philo->protect_write));
		}
	}
}