/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:13:46 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 13:04:28 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    print_state(int state, int  philo_id)
{
	if (state == TAKE_FORK)
	{
		// timestamp_in_ms X has taken a fork
		printf("[timestamp_in_ms] %d has taken a fork\n", philo_id);
	}
}

void	take_forks(t_args *data)
{
	int		philo_id;
	t_philo	*philo;

	philo_id = data->philo_id;
	philo = data->philo;
	if (philo_id % 2 != 0)
	{
		pthread_mutex_lock(&(philo->forks[(philo_id + 1) % 2]));
		pthread_mutex_lock(&(philo->forks[philo_id]));
		print_state(TAKE_FORK, philo_id);
		print_state(TAKE_FORK, philo_id);
	}
	else
	{
		pthread_mutex_lock(&(philo->forks[philo_id]));
		pthread_mutex_lock(&(philo->forks[(philo_id + 1) % 2]));
		print_state(TAKE_FORK, philo_id);
		print_state(TAKE_FORK, philo_id);
	}
}