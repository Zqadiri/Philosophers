/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:42:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 09:43:27 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	check_death(t_args	*arg)
{
	int				i;
	long long			diff;

	i = 0;
	while (i < arg->philo->np)
	{
		pthread_mutex_lock(&(arg->philo->is_eating[arg->philo_id]));
		diff = calculate_timestamp() - arg->philo->timestamp[i];
		// pthread_mutex_lock(&(arg->philo->protect_write));
		// printf ("\nphilo %d: %lld - %ld = %lld\n", i + 1, calculate_timestamp(), arg->philo->timestamp[i], diff);
		// pthread_mutex_unlock(&(arg->philo->protect_write));
		if (diff > arg->philo->time_to_die)
		{
			printf("PHILO %d: DIED\n", i + 1);
			// detach_philo(arg);
			arg->philo->is_dead = 1;
			exit (0);
		}
		pthread_mutex_unlock(&(arg->philo->is_eating[arg->philo_id]));
		i++;
	}
}