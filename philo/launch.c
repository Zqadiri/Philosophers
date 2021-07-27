/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:49:57 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/26 12:53:15 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = calculate_timestamp();
	while (!philo->state->is_dead && !philo->state->is_done)
	{
		take_forks(philo);
		start_eat(philo);
		go_to_sleep(philo);
		think(philo);
	}
	return (NULL);
}

int	create_threads(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * state->np);
	state->time_start = calculate_timestamp();
	while (i < state->np)
	{
		philo[i].philo_id = i;
		philo[i].eating = 0;
		philo[i].times_philo_ate = 0;
		philo[i].state = state;
		pthread_mutex_init(&(philo[i].is_eating), NULL);
		pthread_create(&(philo[i].tid), NULL, philosopher, (void *)&philo[i]);
		usleep(100);
		i++;
	}
	if (pthread_create(&(state->sup), NULL, supervisor, (void *)philo))
		return (0);
	if (pthread_create(&(state->sup_d), NULL, death_supervisor, (void *)philo))
		return (0);
	if (pthread_join(state->sup_d, NULL))
		return (0);
	return (1);
}
