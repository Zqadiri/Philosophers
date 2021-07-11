/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:16:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/11 20:13:41 by zqadiri          ###   ########.fr       */
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

long	calculate_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((long) tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}

void	take_forks(t_philo *philo)
{
	(void)philo;
}

void	start_eat(t_philo *philo)
{
	(void)philo;
}

void	go_to_sleep(t_philo *philo)
{
	(void)philo;
}

void	think(t_philo *philo)
{
	(void)philo;
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

void	*philosopher()
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	while (!philo->is_dead && !philo->is_done)
	{
		take_forks(philo);
		start_eat(philo);
		go_to_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void    launch(t_state *state)
{
	int i;

	i = 0;
	while (i < state->np)
	{
		printf ("%d\n", i);
		state->pid[i] = fork();
		if (state->pid[i] < 0)
			printf ("Error !\n");
		else if (state->pid[i] == 0)
			philosopher();
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_state *state;

	if (argc < 5 || argc > 6)
		printf ("Philo takes at least five arguments !\n");
	else
	{
		state = (t_state *)malloc(sizeof(t_state));
		if (!get_args(state, argv))
			return (0);
		launch(state);
	}
	return (1);
}
