/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 10:43:23 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	start_eat(t_args *data)
{
	int		philo_id;
	t_philo	*philo;

	philo_id = data->philo_id;
	philo = data->philo;
	// pthread_mutex_lock(&(philo->is_eating[philo_id]));
	pthread_mutex_lock(&(data->philo->mutex));
	print_state(EAT, data);
	philo->timestamp[philo_id] = calculate_timestamp();
	philo->death_time[philo_id] = philo->timestamp[philo_id] + philo->time_to_die;
	philo->times_philo_ate[philo_id]++;
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&(data->philo->mutex));
	// pthread_mutex_unlock(&(philo->is_eating[philo_id]));
}
