/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:43:48 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/09 10:20:01 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	detach_philo(t_philo *args)
{
	int		i;

	i = 0;
	while(i < args->state->np)
	{
		pthread_detach(args[i].tid);
		i++;
	}
	pthread_detach(args->state->sup);
	pthread_detach(args->state->sup_d);
	i = 0;
	while (i < args->state->np)
	{
		pthread_mutex_destroy(&(args->state->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(args->is_eating));
	pthread_mutex_destroy(&(args->state->mutex));
	pthread_mutex_destroy(&(args->state->protect_write));
}

int	all_philo_are_done(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->state->np)
	{
		if (philo[i].times_philo_ate < philo->state->nb_must_eat)
			return (0);
		i++;
	}
	philo->state->is_done = 1;
	return (1);
}

void	check_done(t_philo	*philo)
{
	int		done;

	done  = 0;
    // printf ("%d\n", philo->state->nb_must_eat);
	if (philo->state->nb_must_eat != -1)
	{
		while (!done)
		{
            // printf ("philo %d :%d\n", 0, philo[0].times_philo_ate);
            // printf ("philo %d :%d\n", 1, philo[1].times_philo_ate);
            // printf ("philo %d :%d\n", 2, philo[2].times_philo_ate);
            // printf ("philo %d :%d\n", 3, philo[3].times_philo_ate);
            // printf ("philo %d :%d\n", 4, philo[4].times_philo_ate);
			usleep(philo->state->time_to_eat * 1000);
			pthread_mutex_lock(&(philo->state->protect_write));
			done =	all_philo_are_done(philo);
			pthread_mutex_unlock(&(philo->state->protect_write));
		}
	}
}