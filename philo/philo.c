/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:54:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/18 10:27:21 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_args(t_state *state, char **args)
{
	state->np = ft_atoi(args[1]);
	state->time_to_die = ft_atoi(args[2]);
	state->time_to_eat = ft_atoi(args[3]);
	state->time_to_sleep = ft_atoi(args[4]);
	if (args[5] != NULL)
		state->nb_must_eat = ft_atoi(args[5]);
	else
		state->nb_must_eat = -1;
	state->is_dead = 0;
	state->is_done = 0;
	state->forks = (pthread_mutex_t *)
		malloc(state->np * sizeof(pthread_mutex_t));
	if (state->forks == NULL)
		return (0);
	return (1);
}

int	init_mutexes(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->np)
	{
		pthread_mutex_init(&(state->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(state->mutex), NULL);
	pthread_mutex_init(&(state->protect_write), NULL);
	return (1);
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

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_state	*state;

	philo = NULL;
	if (argc < 5 || argc > 6)
		printf ("Philo takes at least five arguments !\n");
	else
	{
		state = (t_state *)malloc(sizeof(t_state));
		if (!get_args(state, argv))
			return (0);
		if (!is_valid_args(state, argv))
			return (0);
		if (!init_mutexes(state))
			return (0);
		create_threads(state, philo);
	}
	return (1);
}
