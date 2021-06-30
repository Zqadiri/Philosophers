/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:43:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 20:31:52 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	go_to_sleep(t_args *data)
{
	pthread_mutex_unlock(&(data->philo->forks[data->philo_id]));
	pthread_mutex_unlock(&(data->philo->forks[(data->philo_id + 1) % 2]));
	print_state(SLEEP, data);
	_do(data->philo->time_to_sleep);
}