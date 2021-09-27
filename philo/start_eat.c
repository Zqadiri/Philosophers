/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 18:25:24 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eat(t_philo *philo)
{
	if (philo->state->is_done || philo->state->is_dead)
		return ;
	// pthread_mutex_lock(&(philo->is_eating));
	philo->eating = 1;
	// pthread_mutex_unlock(&(philo->is_eating));
	print_state(EAT, philo);
	philo->last_meal = calculate_timestamp();
	usleep(philo->state->time_to_eat * 1000 - 10000);
	while (calculate_timestamp() - philo->last_meal < philo->state->time_to_eat)
		;
	philo->times_philo_ate++;
	// pthread_mutex_lock(&(philo->is_eating));
	philo->eating = 0;
	// pthread_mutex_unlock(&(philo->is_eating));
	pthread_mutex_unlock(&(philo->state->forks[philo->philo_id]));
	pthread_mutex_unlock(&(philo->state->forks[(philo->philo_id + 1)
			% philo->state->np]));
}
