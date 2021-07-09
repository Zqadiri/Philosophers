/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/09 21:47:02 by zqadiri          ###   ########.fr       */
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
		eating = time_to_eat - (((tv2.tv_sec * TO_MICRO) - (tv1.tv_sec * TO_MICRO))
		+ (tv2.tv_usec - tv2.tv_usec));
		if (eating < 0)
			break;
		if (eating > 0)
		{
			not_done = 0;
			usleep(eating);
		}
		usleep(50);
	}
}

void	start_eat(t_philo *philo)
{
	if (philo->state->is_done || philo->state->is_dead)
		return ;
	philo->eating = 1;
	print_state(EAT, philo);
	_do(philo->state->time_to_eat * 1000);
	philo->last_meal = calculate_timestamp();
	philo->eating = 0;
	philo->times_philo_ate++;
	pthread_mutex_unlock(&(philo->is_eating));
}
