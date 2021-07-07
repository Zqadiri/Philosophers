/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:43:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/07 15:22:47 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

long long	calculate_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((long long) tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}

void	go_to_sleep(t_args *data)
{
	if (data->philo->is_done)
		return ;
	print_state(SLEEP, data);
	pthread_mutex_unlock(&(data->philo->forks[data->philo_id]));
	pthread_mutex_unlock(&(data->philo->forks[(data->philo_id + 1) % 2]));
	usleep(data->philo->time_to_sleep * 1000);
}