/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:49:57 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 20:57:18 by zqadiri          ###   ########.fr       */
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

void    *supervisor(void *arg)
{
	t_args	*args;
	int		philo_id;
	t_philo	*philo;

	args = (t_args *)arg;
	philo_id = args->philo_id;
	philo = args->philo;
	// while (!philo->is_dead && !philo->is_done)
	// {
	// 	pthread_mutex_lock(&(philo->protect_write));
	// 	printf ("%d\n", args->philo_id);
	// 	pthread_mutex_unlock(&(philo->protect_write));
	// }
	return (NULL);
}

void    exit_error(void)
{
	// destroy mutex
	// detach threads
	exit(EXIT_FAILURE);
}

static  void    create_supervisor(t_args *arg)
{
	if (pthread_create(&(arg->philo->sup), NULL, &supervisor, (void *)arg))
		exit_error();
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
	create_supervisor(args);
	if (pthread_join(philo->sup, NULL))
			return (0);
	i = 0;
	while(i < philo->np)
	{
		if (pthread_join(philo->tid[i], NULL))
			return (0);
		i++;
	}
	return (1);
}