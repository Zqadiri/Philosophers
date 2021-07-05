/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:49:57 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/30 20:57:18 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    *philosopher(void *arg)
{
	t_args	*args;
	int		philo_id;
	t_philo	*philo;

	args = (t_args *)arg;
	philo_id = args->philo_id;
	philo = args->philo;
	while (!philo->is_dead && !philo->is_done)
	{
		take_forks(args);
		start_eat(args);
		go_to_sleep(args);
		think(args);
	}
	return (NULL);
}

void    exit_error(void)
{
	// destroy mutex
	// detach threads
	exit(EXIT_FAILURE);
}

void	all_philo_are_done(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->np)
	{
		if (philo->times_philo_ate[i] != philo->nb_must_eat)
		{
			philo->is_done = 0;
			return ;
		}
		philo->is_done = 1;
	}
}

void	detach_philo(t_args *args)
{
	int		i;

	i = 0;
	while(i < args->philo->np)
	{
		pthread_detach(args->philo->tid[i]);
		i++;
	}
	print_state(DONE, args);
}

void	check_done(t_args	*arg)
{
	int		i;

	if (arg->philo->nb_must_eat > 0)
	{
		_do(arg->philo->time_to_eat);
		i = 0;
		while (i < arg->philo->np)
		{
			if (arg->philo->times_philo_ate[i] >= arg->philo->nb_must_eat)
				all_philo_are_done(arg->philo);
			else
				break;	
			i++;
		}
		if (arg->philo->is_done)
			detach_philo(arg);	
	}
}

void	check_death(t_args	*arg)
{
	struct timeval 	tv_now;
	int				time_now;
	int				i;
	size_t			diff;

	i = 0;
	gettimeofday(&tv_now, NULL);
	time_now = ((tv_now.tv_sec * 1000) + (tv_now.tv_usec / 1000));
	while (i < arg->philo->np)
	{
		diff = time_now - arg->philo->timestamp[arg->philo_id];
		if (diff > arg->philo->time_to_die)
		{
			print_state(DIED, arg);
			// detach_philo(arg);
			exit (0);
		}
		i++;
	}
}

void    *supervisor(void *arg)
{
	t_args	*args;
	int		philo_id;
	t_philo	*philo;

	args = (t_args *)arg;
	philo_id = args->philo_id;
	philo = args->philo;
	while (!philo->is_dead && !philo->is_done)
	{
		check_done(args);
		check_death(args);
	}
	return (NULL);
}

int		create_threads(t_philo *philo)
{
	int			i;
	t_args		*args;

	i = 0;
	args = NULL;
	while (i < philo->np)
	{
		args = (t_args *)malloc(sizeof(t_args));
		args->philo_id = i;
		args->philo = philo; 
		if (pthread_create(&(philo->tid[i]), NULL, philosopher, (void *)args))
			return (0);
		i++;
	}
	if (pthread_create(&(philo->sup), NULL, supervisor, (void *)args))
		exit_error();
	i = 0;
	while(i < philo->np)
	{
		if (pthread_join(philo->tid[i], NULL))
			return (0);
		i++;
	}
	if (pthread_join(philo->sup, NULL))
		return (0);
	return (1);
}