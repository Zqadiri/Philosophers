/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:13:46 by zqadiri           #+#    #+#             */
/*   Updated: 2021/10/17 11:59:16 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		signe;
	long	x;

	signe = 1;
	x = 0;
	while (*str != '\0' && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		x = (x * 10) + ((char)*str - '0');
		if (x > 4294967296)
		{
			if (signe > 0)
				return (-1);
			return (0);
		}
		str++;
	}
	return (x * signe);
}

void	print_state(int state, t_philo *philo)
{
	pthread_mutex_lock(&(philo->state->protect_write));
	printf("%lld", calculate_timestamp() - philo->state->time_start);
	if (state == TAKE_FORK)
		printf(" %d has taken a fork\n", philo->philo_id + 1);
	if (state == EAT)
		printf(" %d is eating\n", philo->philo_id + 1);
	if (state == SLEEP)
		printf(" %d is sleeping\n", philo->philo_id + 1);
	if (state == THINK)
		printf(" %d is thinking\n", philo->philo_id + 1);
	if (state == DIED)
		printf(" %d died\n", philo->philo_id + 1);
	if (state != DIED)
		pthread_mutex_unlock(&(philo->state->protect_write));
}

/*
	A race condition occurs when two or more threads can access shared data and 
	they try to change it at the same time. Because the thread scheduling algorithm 
	can swap between threads at any time, you don't know the order in which 
	the threads will attempt to access the shared data.
*/

void	take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(&(philo->state->forks[(philo->philo_id + 1)
				% philo->state->np]));
		print_state(TAKE_FORK, philo);
		pthread_mutex_lock(&(philo->state->forks[philo->philo_id]));
		print_state(TAKE_FORK, philo);
	}
	else
	{
		pthread_mutex_lock(&(philo->state->forks[philo->philo_id]));
		print_state(TAKE_FORK, philo);
		pthread_mutex_lock(&(philo->state->forks[(philo->philo_id + 1)
				% philo->state->np]));
		print_state(TAKE_FORK, philo);
	}
}
