/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/08 16:49:02 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	start_eat(t_philo *philo)
{
	if (philo->state->is_done)
		return ;
	pthread_mutex_lock(&(philo->state->is_eating));
	philo->eating = 1;
	print_state(EAT, philo);
	usleep(philo->state->time_to_eat * 1000);
	philo->last_meal = calculate_timestamp();
	philo->eating = 0;
	philo->times_philo_ate++;
	pthread_mutex_unlock(&(philo->state->is_eating));
}
