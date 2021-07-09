/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:43:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/09 21:47:19 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	go_to_sleep(t_philo *philo)
{
	if (philo->state->is_done)
		return ;
	print_state(SLEEP, philo);
	pthread_mutex_unlock(&(philo->state->forks[philo->philo_id]));
	pthread_mutex_unlock(&(philo->state->forks[(philo->philo_id + 1) % 2]));
	_do(philo->state->time_to_sleep * 1000);
}