/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:42:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 17:30:21 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	check_death(t_args	*arg)
{
	int				i;

	i = 0;
	while (i < arg->philo->np)
	{
		// pthread_mutex_lock(&(arg->philo->is_eating[i]));
		if (arg->philo->death_time < calculate_timestamp() && !arg->philo->eating)
		{
			pthread_mutex_lock(&(arg->philo->protect_write));
			printf("PHILO %d: DIED\n", i + 1);
			pthread_mutex_unlock(&(arg->philo->protect_write));
			arg->philo->is_dead = 1;
		}
		// pthread_mutex_unlock(&(arg->philo->is_eating[i]));
		i++;
	}
}

void    *death_supervisor(void *arg)
{
	t_args	*args;
	int		philo_id;
	t_philo	*philo;

	args = (t_args *)arg;
	philo_id = args->philo_id;
	philo = args->philo;
	philo->death_time = calculate_timestamp() + philo->time_to_die;
	while (!philo->is_dead && !philo->is_done)
		check_death(args);
	if (philo->is_dead)
	{
		detach_philo(args);
		printf("\t dead \n");
		exit(0);
	}
	return(NULL);
}

// pthread_mutex_lock(&(arg->philo->protect_write));
// printf ("\nphilo %d: %lld - %ld = %lld\n", i + 1, calculate_timestamp(), arg->philo->timestamp[i], diff);
// pthread_mutex_unlock(&(arg->philo->protect_write));