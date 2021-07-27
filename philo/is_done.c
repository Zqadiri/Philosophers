/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:48 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 18:34:22 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	*supervisor(void *arg)
{
	t_philo	*philo;
	int		done;

	done = 0;
	philo = (t_philo *)arg;
	while (!philo->state->is_done)
	{
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
	pthread_mutex_lock(&(philo->state->protect_write));
	return (NULL);
}
