/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:49:57 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/08 19:58:00 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    *philosopher(void *arg)
{
	t_philo	*philo;
	// long	diff;

	philo = (t_philo *)arg;
	while (1) // ! change the while loop
	{
		take_forks(philo);
		start_eat(philo);
		go_to_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void    exit_error(void)
{
	// destroy mutex
	// detach threads
	exit(15);
}

void    *supervisor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->state->is_dead && !philo->state->is_done)
		check_done(philo);
	if (philo->state->is_done)
	{
		detach_philo(philo);
		printf("\t done \n");
		exit(0);
	}
	return(NULL);
}

int		create_threads(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * state->np);
	state->time_start = calculate_timestamp();
	while (i < state->np)
	{
		philo[i].philo_id = i;
		philo[i].state = state;
		philo[i].eating = 0;
		philo[i].last_meal = calculate_timestamp();
		philo[i].times_philo_ate = 0;
		pthread_mutex_init(&(philo[i].is_eating), NULL);
		if (pthread_create(&(philo[i].tid), NULL, philosopher, (void *)&philo[i]))
			return (0);
		i++;
	}
	if (pthread_create(&(state->sup), NULL, supervisor, (void *)philo))
		exit_error();
	if (pthread_create(&(state->sup_d), NULL, death_supervisor, (void *)philo))
		exit_error();
	i = 0;
	while(i < state->np)
	{
		if (pthread_join(philo[i].tid, NULL))
			return (0);
		i++;
	}
	if (pthread_join(state->sup, NULL))
		return (0);
	if (pthread_join(state->sup_d, NULL))
		return (0);
	return (1);
}