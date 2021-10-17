/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/10/17 11:36:04 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eat(t_philo *philo)
{
	philo->eating = 1;
	print_state(EAT, philo);
	philo->last_meal = calculate_timestamp();
	usleep(philo->state->time_to_eat * 1000 - 10000);
	while (calculate_timestamp() - philo->last_meal < philo->state->time_to_eat)
		;
	philo->times_philo_ate++;
	philo->eating = 0;
	pthread_mutex_unlock(&(philo->state->forks[philo->philo_id]));
	pthread_mutex_unlock(&(philo->state->forks[(philo->philo_id + 1)
			% philo->state->np]));
}
