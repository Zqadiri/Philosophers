/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:42:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/08 16:55:37 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// void	check_death(t_args	*arg)
// {
// 	int				i;

// 	i = 0;
// 	// usleep(arg->philo->time_to_eat * 1000);
// 	while (i < arg[0].philo->np)
// 	{
// 		// pthread_mutex_lock(&(arg->philo->protect_write));
// 		// printf ("\nphilo %d: %lld -  %ld	%ld\n", i + 1, 
// 		// calculate_timestamp() - arg[i].philo->time_start, arg[i].philo->death_time  - arg[i].philo->time_start, arg[i].philo->last_eatting);
// 		// pthread_mutex_unlock(&(arg->philo->protect_write));
// 		pthread_mutex_lock(&(arg[i].philo->is_eating));
// 		if (arg[i].philo->death_time < calculate_timestamp())
// 		{
// 			// pthread_mutex_lock(&(arg[i].philo->protect_write));
// 			printf("PHILO %d: DIED\n", i + 1);
// 			arg[i].philo->is_dead = 1;
// 			exit(0);
// 		}
// 		pthread_mutex_unlock(&(arg[i].philo->is_eating));
// 		i++;
// 	}
// }

void    *death_supervisor(void *arg)
{
	t_philo	*philo;
	// t_philo	*philo;

	philo = (t_philo *)arg;
	// philo = args->philo;
	// while (!philo->is_dead)
	// 	check_death(args);
	// if (philo->is_dead)
	// {
	// 	detach_philo(args);
	// 	printf("\t dead \n");
	// 	exit(0);
	// }
	return(NULL);
}

