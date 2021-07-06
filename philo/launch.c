/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:49:57 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 11:14:18 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    *philosopher(void *arg)
{
	t_args	*args;
	int		philo_id;
	t_philo	*philo;

	args = (t_args *)arg;
	philo_id = args->philo_id;
	philo = args->philo;
	while (!philo->is_dead && !philo->is_done)
	{
		take_forks(args);
		start_eat(args);
		go_to_sleep(args);
		think(args);
	}
	return (NULL);
}

void    exit_error(void)
{
	// destroy mutex
	// detach threads
	exit(EXIT_FAILURE);
}

void    *supervisor(void *arg)
{
	t_args	*args;
	int		philo_id;
	t_philo	*philo;

	args = (t_args *)arg;
	philo_id = args->philo_id;
	philo = args->philo;
	while (!philo->is_dead && !philo->is_done)
	{
		check_done(args);
		// check_death(args);
	}
	if (philo->is_done)
	{
		detach_philo(args);
		print_state(DONE, args);
	}
	return(NULL);
}

int		create_threads(t_philo *philo)
{
	int			i;
	t_args		*args;

	i = 0;
	args = NULL;
	while (i < philo->np)
	{
		args = (t_args *)malloc(sizeof(t_args));
		args->philo_id = i;
		args->philo = philo; 
		if (pthread_create(&(philo->tid[i]), NULL, philosopher, (void *)args))
			return (0);
		i++;
	}
	if (pthread_create(&(philo->sup), NULL, supervisor, (void *)args))
		exit_error();
	i = 0;
	while(i < philo->np)
	{
		if (pthread_join(philo->tid[i], NULL))
			return (0);
		i++;
	}
	if (pthread_join(philo->sup, NULL))
		return (0);
	return (1);
}