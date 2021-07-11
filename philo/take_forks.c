/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:13:46 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/11 11:04:32 by zqadiri          ###   ########.fr       */
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
	int	diff;
	int	now;

	pthread_mutex_lock(&(philo->state->protect_write));
	now = calculate_timestamp();
	diff = now - philo->state->time_start;
	printf("%d", diff);
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

void	take_forks(t_philo *philo)
{
	if (philo->state->is_done || philo->state->is_dead)
		return ;
	pthread_mutex_lock(&(philo->state->mutex));
	if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_lock(&(philo->state->forks[(philo->philo_id + 1) % 2]));
		print_state(TAKE_FORK, philo);
		pthread_mutex_lock(&(philo->state->forks[philo->philo_id]));
		print_state(TAKE_FORK, philo);
	}
	else
	{
		pthread_mutex_lock(&(philo->state->forks[philo->philo_id]));
		print_state(TAKE_FORK, philo);
		pthread_mutex_lock(&(philo->state->forks[(philo->philo_id + 1) % 2]));
		print_state(TAKE_FORK, philo);
	}
	pthread_mutex_lock(&(philo->is_eating));
	pthread_mutex_unlock(&(philo->state->mutex));
}
