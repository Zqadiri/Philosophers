/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:55:35 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/29 20:35:29 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	print_args(t_philo *philo, t_state *state)
{
	printf ("%d\n", philo->np);
	printf ("%zu\n", philo->time_to_die);
	printf ("%zu\n", philo->time_to_eat);
	printf ("%zu\n", philo->time_to_sleep);
	printf ("%d\n", philo->nb_must_eat);
	printf ("time_start : %ld\n", state->time_start);
}

int	init(t_philo *philo, t_state *state)
{
    struct timeval current_time;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (0);
    state = malloc(sizeof(t_state));
	if (state == NULL)
		return (0);
	philo->np = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->nb_must_eat = 0;
    philo->is_done = 0;
    philo->is_dead = 0;
    gettimeofday(&current_time, NULL);
    state->time_start = current_time.tv_usec;
	return (1);
}
