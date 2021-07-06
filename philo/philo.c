/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:54:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 21:27:52 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// * number_of_philosophers time_to_die
// * time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

// ! switch to ft_atoi && ft_memset

int	get_args(t_philo *philo, char **args)
{
	philo->np = atoi(args[1]);
	philo->time_to_die = atoi(args[2]); // ? milli
	philo->time_to_eat = atoi(args[3]);
	philo->time_to_sleep = atoi(args[4]);
	if (args[5] != NULL)
		philo->nb_must_eat = atoi(args[5]);
	else
		philo->nb_must_eat = -1;
    philo->tid = (pthread_t *)malloc(philo->np * sizeof(pthread_t));
	if ( philo->tid == NULL)
		return (0);
	philo->is_eating = (pthread_mutex_t *)malloc(philo->np * sizeof(pthread_mutex_t));
	if (philo->is_eating == NULL)
		return (0);
	philo->forks = (pthread_mutex_t *)malloc(philo->np * sizeof(pthread_mutex_t));
	if (philo->forks == NULL)
		return (0);
	philo->times_philo_ate = (int *)malloc(philo->np * sizeof(int));
	if (philo->times_philo_ate == NULL)
		return (0);
	memset(philo->times_philo_ate, 0, philo->np);
	philo->timestamp = (long*)malloc(philo->np * sizeof(long));
	if (philo->timestamp == NULL)
		return (0);
	philo->death_time = (long*)malloc(philo->np * sizeof(long));
	if (philo->death_time == NULL)
		return (0);
	return (1);
}

int		init_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->np)
	{
		philo->timestamp[i] = calculate_timestamp();
		philo->death_time[i] = calculate_timestamp();
		pthread_mutex_init(&(philo->is_eating[i]), NULL);
		pthread_mutex_init(&(philo->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(philo->mutex), NULL);
	pthread_mutex_init(&(philo->protect_write), NULL);
	philo->time_start = calculate_timestamp();
	return (1);
}

int     main(int argc, char *argv[])
{
	t_philo philo;

	if (argc < 5 || argc > 6)
		printf ("Philo takes at least five arguments !\n");
	else
	{
		if (!init(&philo))
			return (0);
		if (!get_args(&philo, argv))
			return (0);
		if (!init_mutexes(&philo))
			return (0);
    	// print_args(&philo);		
		if (!create_threads(&philo))
			exit_error();
	}
	return (1);
}