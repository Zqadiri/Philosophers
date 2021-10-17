/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:43:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/10/17 11:28:55 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_to_sleep(t_philo *philo)
{
	long long	time;

	print_state(SLEEP, philo);
	time = calculate_timestamp();
	usleep(philo->state->time_to_sleep * 1000 - 10000);
	while (calculate_timestamp() - time < philo->state->time_to_sleep)
		;
	return ;
}

void	think(t_philo *philo)
{
	print_state(THINK, philo);
}
