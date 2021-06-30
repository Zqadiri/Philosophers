/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:54:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 15:19:49 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// * number_of_philosophers time_to_die
// * time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

// ! switch to ft_atoi

int	get_args(t_philo *philo, char **args)
{
	philo->np = atoi(args[1]);
	philo->time_to_die = atoi(args[2]) * 1000;
	philo->time_to_eat = atoi(args[3]) * 1000;
	philo->time_to_sleep = atoi(args[4]) * 1000;
	if (args[5] != NULL)
		philo->np = atoi(args[1]);
    philo->tid = (pthread_t *)malloc(philo->np * sizeof(pthread_t));
	if ( philo->tid == NULL)
		return (0);
	pthread_mutex_init(&(philo->protect_forks), NULL);
	pthread_mutex_init(&(philo->protect_write), NULL);
	philo->forks = (pthread_mutex_t *)malloc(philo->np * sizeof(pthread_mutex_t));
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
    	print_args(&philo);		
		if (!create_threads(&philo))
			exit_error();
	}
	return (1);
}