/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:54:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/10 16:06:30 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// * number_of_philosophers time_to_die
// * time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

// ! switch to ft_atoi && ft_memset

int	get_args(t_state *state, char **args)
{
	state->np = atoi(args[1]);
	if (state->np < 0 || state->np > 200)
		printf("Try a number of philosophers between 0 & 200 *_-\n");
	state->time_to_die = atoi(args[2]); // ? milli
	state->time_to_eat = atoi(args[3]);
	state->time_to_sleep = atoi(args[4]);
	if (state->time_to_die < 60 || state->time_to_eat < 60 || state->time_to_sleep < 60)
		printf("[time_to_die] [time_to_sleep] [time_to_eat] prefered to be  > 60ms\n");
	if (args[5] != NULL)
		state->nb_must_eat = atoi(args[5]);
	else
		state->nb_must_eat = -1;
	state->time_start = calculate_timestamp();
	state->is_dead = 0;
	state->is_done = 0;
	state->forks = (pthread_mutex_t *)malloc(state->np * sizeof(pthread_mutex_t));
	if (state->forks == NULL)
		return (0);
	return (1);
}

int		init_mutexes(t_state *state)
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
	pthread_mutex_init(&(state->someone_is_dead), NULL);
	return (1);
}

int     main(int argc, char *argv[])
{
	t_philo *philo;
	t_state *state;

	if (argc < 5 || argc > 6)
		printf ("Philo takes at least five arguments !\n");
	else
	{
		state = (t_state *)malloc(sizeof(t_state));	
		if (!get_args(state, argv))
			return (0);
    	// print_args(state);
		philo = malloc(sizeof(t_philo) * state->np);
		if (!init_mutexes(state))
			return (0);
		if (!create_threads(state, philo))
			return(EXIT_SUCCESS);
			printf ("here\n");
		// pthread_mutex_lock(&(state->someone_is_dead)); // ? death lock
		// pthread_mutex_unlock(&(state->someone_is_dead));
	}
	return (1);
}
