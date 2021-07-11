/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:42:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/11 10:44:29 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo	*philo)
{
	int		i;
	long	diff;

	i = 0;
	while (i < philo->state->np)
	{
		pthread_mutex_lock(&(philo[i].is_eating));
		diff = calculate_timestamp() - philo[i].last_meal;
		if (diff > philo->state->time_to_die && !philo[i].eating)
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

	philo = (t_philo *)arg;
	while (!philo->state->is_dead)
		check_death(philo);
	if (philo->state->is_dead)
	{
		print_state(DIED, philo);
		return (NULL);
	}
	return (NULL);
}
