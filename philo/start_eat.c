/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 17:28:27 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	start_eat(t_args *data)
{
	int		philo_id;
	t_philo	*philo;

	philo_id = data->philo_id;
	philo = data->philo;
	if (data->philo->is_done)
		return ;
	pthread_mutex_lock(&(philo->is_eating));
	philo->eating = 1;
	print_state(EAT, data);
	philo->timestamp[philo_id] = calculate_timestamp();
	philo->death_time = calculate_timestamp() + philo->time_to_die;
	usleep(philo->time_to_eat * 1000);
	philo->eating = 0;
	philo->times_philo_ate[philo_id]++;
	pthread_mutex_unlock(&(philo->is_eating));
}
