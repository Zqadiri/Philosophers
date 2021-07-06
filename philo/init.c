/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:55:35 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/06 10:20:14 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	print_args(t_philo *philo)
{
	printf ("philo->np :%d\n", philo->np);
	printf ("philo->time_to_die %d\n", philo->time_to_die);
	printf ("philo->time_to_eat %d\n", philo->time_to_eat);
	printf ("philo->time_to_sleep %d\n", philo->time_to_sleep);
	printf ("philo->nb_must_eat %d\n", philo->nb_must_eat);
	int i = 0;
	while (i < philo->np)
	{
		printf ("%d\n", philo->times_philo_ate[i]);
		i ++;
	}
}

int	init(t_philo *philo)
{
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (0);
	philo->np = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	// philo->nb_must_eat = -1;
    philo->is_done = 0;
    philo->is_dead = 0;
	return (1);
}
