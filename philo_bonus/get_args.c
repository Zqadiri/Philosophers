/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:39:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 19:29:07 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	display_state(int state, t_philo *philo)
{
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
}

int	is_valid_args(t_state *state, char *argv[])
{
	if (state->np <= 0 || state->np > 200)
	{
		printf("Try a number of philosophers between 0 & 200 *_-\n");
		return (0);
	}
	if (state->time_to_die < 60 || state->time_to_eat < 60
		|| state->time_to_sleep < 60)
	{
		printf("[time_to_die][time_to_sleep][time_to_eat] must be > 60ms\n");
		return (0);
	}
	if (state->nb_must_eat <= 0 && argv[5] != NULL)
	{
		printf ("[number_of_times_each_philosopher_must_eat] must be > 0\n");
		return (0);
	}
	return (1);
}

int	store_args(t_state *state, char **args)
{
	state->np = ft_atoi(args[1]);
	state->time_to_die = ft_atoi(args[2]);
	state->time_to_eat = ft_atoi(args[3]);
	state->time_to_sleep = ft_atoi(args[4]);
	if (args[5] != NULL)
		state->nb_must_eat = ft_atoi(args[5]);
	else
		state->nb_must_eat = -1;
	return (1);
}
