/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:33:40 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/09 10:31:13 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    think(t_philo *philo)
{
	if (philo->state->is_done || philo->state->is_dead)
		return ;
	print_state(THINK, philo);
}   