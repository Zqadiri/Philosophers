/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 21:39:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/11 21:40:34 by zqadiri          ###   ########.fr       */
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

int	get_args(t_state *state, char **args)
{
	state->np = ft_atoi(args[1]);
	if (state->np < 0 || state->np > 200)
		printf("Try a number of philosophers between 0 & 200 *_-\n");
	state->time_to_die = ft_atoi(args[2]);
	state->time_to_eat = ft_atoi(args[3]);
	state->time_to_sleep = ft_atoi(args[4]);
	if (state->time_to_die < 60 || state->time_to_eat < 60
		|| state->time_to_sleep < 60)
		printf("[time_to_die][time_to_sleep][time_to_eat] must be > 60ms\n");
	if (args[5] != NULL)
		state->nb_must_eat = ft_atoi(args[5]);
	else
		state->nb_must_eat = -1;
	state->time_start = calculate_timestamp();
	state->pid = (pid_t *)malloc(state->np * sizeof(pid_t));
	return (1);
}
