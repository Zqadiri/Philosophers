/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:13:46 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 11:13:05 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	print_state(int state, t_args *data)
{
	int	diff;
	int now;

	pthread_mutex_lock(&(data->philo->protect_write));
	if (state == DONE)
	{
		printf("\t done \n");
		exit(EXIT_FAILURE);
	}
	now = calculate_timestamp();
	diff = now - data->philo->time_start;
	printf("%d", diff);
	if (state == TAKE_FORK)
		printf(" %d has taken a fork\n", data->philo_id + 1);
	if (state == EAT)
		printf(" %d is eating\n", data->philo_id + 1);
	if (state == SLEEP)
		printf(" %d is sleeping\n", data->philo_id + 1);
	if (state == THINK)
		printf(" %d is thinking\n", data->philo_id + 1);
	if (state == DIED)
		printf(" %d died\n", data->philo_id + 1);
	pthread_mutex_unlock(&(data->philo->protect_write));
}

void	take_forks(t_args *data)
{
	int		philo_id;
	t_philo	*philo;

	philo_id = data->philo_id;
	philo = data->philo;
	pthread_mutex_lock(&(data->philo->mutex));
	pthread_mutex_lock(&(philo->forks[philo_id]));
	print_state(TAKE_FORK, data);
	pthread_mutex_lock(&(philo->forks[(philo_id + 1) % 2]));
	print_state(TAKE_FORK, data);
	pthread_mutex_unlock(&(data->philo->mutex));
}
