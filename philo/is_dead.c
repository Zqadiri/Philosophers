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

	philo = (t_philo *)arg;
	while (!philo->state->is_dead && !philo->state->is_done)
	{
		i = 0;
		while (i < philo->state->np)
		{
			if (calculate_timestamp() - philo[i].last_meal
				> philo->state->time_to_die)
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
