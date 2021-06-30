/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:28:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 16:39:20 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	is_eating(size_t time_to_eat)
{
    struct timeval	tv1;
    struct timeval	tv2;
	int				not_done;
	int				eating;

	gettimeofday(&tv1, NULL);
	not_done = 1;
	while (not_done)
	{
		gettimeofday(&tv2, NULL);
		eating = time_to_eat - (((tv2.tv_sec * TO_MICRO) - (tv1.tv_sec * TO_MICRO))
		+ (tv2.tv_usec - tv2.tv_usec));
		// printf("eating time : %d\n", eating);
		// printf("time_to_eat : %zu\n", time_to_eat);
		if (eating < 0)
			// not_done = 0;
			break;
		if (eating > 0)
		{
			usleep(eating);
			// not_done = 0;
			break;
		}
		usleep(50);
	}
}

void	start_eat(t_args *data)
{
	int		philo_id;
	t_philo	*philo;

	philo_id = data->philo_id;
	philo = data->philo;
	pthread_mutex_lock(&(data->philo->is_eating));
    print_state(EAT, data);
	is_eating(philo->time_to_eat);
	// ! abort
	// philo->times_philo_ate[philo_id]++;
	// * unlock forks
	pthread_mutex_unlock(&(data->philo->is_eating));
}
