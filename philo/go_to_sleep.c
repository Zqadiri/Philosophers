/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:43:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 18:22:40 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_to_sleep(t_philo *philo)
{
	long long	time;

	if (philo->state->is_done)
		return ;
	print_state(SLEEP, philo);
	time = calculate_timestamp();
	usleep(philo->state->time_to_sleep * 1000 - 10000);
	while (calculate_timestamp() - time < philo->state->time_to_sleep)
		;
	return ;
}
