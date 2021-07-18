/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:42:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/18 10:38:37 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo	*philo)
{
	int		i;

	i = 0;
	while (i < philo->state->np)
	{
		pthread_mutex_lock(&(philo[i].is_eating));
		if (calculate_timestamp() - philo[i].last_meal
			>= philo->state->time_to_die && !philo[i].eating)
		{
			philo->state->is_dead = 1;
			return ;
		}
		pthread_mutex_unlock(&(philo[i].is_eating));
		i++;
	}
	return ;
}

void	*death_supervisor(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (!philo->state->is_dead)
	{
		i = 0;
		while (i < philo->state->np)
		{
			if (calculate_timestamp() - philo[i].last_meal
				>= philo->state->time_to_die && !philo[i].eating)
			{
				print_state(DIED, philo);
				philo->state->is_dead = 1;
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
