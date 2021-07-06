/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 20:42:59 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	_do(size_t time_to_eat)
{
	struct timeval	tv1;
	struct timeval	tv2;
	int				not_done;
	int				eating;

	gettimeofday(&tv1, NULL);
	not_done = 1;
	while (not_done)
	{
		gettimeofday(&tv2, NULL);
		eating = (time_to_eat * 1000)  - (((tv2.tv_sec * TO_MICRO) - (tv1.tv_sec * TO_MICRO))
		+ (tv2.tv_usec - tv2.tv_usec));
		if (eating < 0)
			break;
		if (eating > 0)
		{
			not_done = 0;
			usleep(eating);
		}
	}
		usleep(50);
}

void	start_eat(t_args *data)
{
	int		philo_id;
	t_philo	*philo;

	philo_id = data->philo_id;
	philo = data->philo;
	pthread_mutex_lock(&(philo->is_eating[philo_id]));
	print_state(EAT, data);
	philo->timestamp[philo_id] = calculate_timestamp();
	philo->death_time[philo_id] = philo->timestamp[philo_id] + philo->time_to_die;
	philo->times_philo_ate[philo_id]++;
	// _do(philo->time_to_eat);
	usleep(philo->time_to_eat * 1000);
	// while (calculate_timestamp() - philo->timestamp[philo_id] >= philo->time_to_eat);
	pthread_mutex_unlock(&(philo->is_eating[philo_id]));
}
