/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:42:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 18:28:55 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_supervisor(void *arg)
{
	t_philo	*philo;
	int		i;

	usleep(100);
	philo = (t_philo *)arg;
	while (!philo->state->is_dead && !philo->state->is_done)
	{
		i = 0;
		while (i < philo->state->np)
		{
			pthread_mutex_lock(&(philo[i].is_eating));
			if (philo[i].eating == 0 && calculate_timestamp() - philo[i].last_meal
				> philo->state->time_to_die)
			{
				print_state(DIED, &philo[i]);
				philo->state->is_dead = 1;
				return (NULL);
			}
			pthread_mutex_unlock(&(philo[i].is_eating));
			i++;
		}
	}
	return (NULL);
}
