/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:55:35 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/08 18:58:30 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	print_args(t_state *state)
{
	printf ("philo->np :%d\n", state->np);
	printf ("state->time_to_die %d\n", state->time_to_die);
	printf ("state->time_to_eat %d\n", state->time_to_eat);
	printf ("state->time_to_sleep %d\n", state->time_to_sleep);
	printf ("state->nb_must_eat %d\n", state->nb_must_eat);
}

long	calculate_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((long) tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}
