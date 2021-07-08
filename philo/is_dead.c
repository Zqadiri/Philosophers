/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:42:53 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/08 20:34:35 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	check_death(t_philo	*philo)
{
	int		i;
	long	diff;

	i = 0;
	while (i < philo->state->np)
	{
		pthread_mutex_lock(&(philo[i].is_eating));
		diff = calculate_timestamp() - philo[i].last_meal;
		if (diff > philo->state->time_to_die && !philo[i].eating)
		{
			// pthread_mutex_lock(&(philo->state->mutex));
			printf("PHILO %d: DIED\n", i + 1);
			printf ("\nphilo %d : [%ld]  [%ld ]\n", i + 1, diff, philo[i].last_meal);
			philo->state->is_dead = 1;
			exit(0);
		}
		pthread_mutex_unlock(&(philo[i].is_eating));
		i++;
	}
}


void    *death_supervisor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->state->is_dead && !philo->state->is_done)
		check_death(philo);
	// if (philo->state->is_done)
	// {
	// 	detach_philo(philo);
	// 	printf("\t dead \n");
	// 	exit(0);
	// }
	return(NULL);
}
