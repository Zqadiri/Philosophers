/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:16:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/27 19:38:48 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pick_up_forks(t_philo *philo)
{
	sem_wait(&(philo->forks[philo->philo_id]));
	display_state(TAKE_FORK, philo);
	sem_wait(&(philo->forks[(philo->philo_id + 1) % philo->state->np]));
	display_state(TAKE_FORK, philo);
}

void	*philosopher(t_philo *philo)
{
	while (1)
	{
		philo->time_start = calculate_timestamp();
		pick_up_forks(philo);
		// start_eat(philo);
		// go_to_sleep(philo);
		// think(philo);
		usleep(100);
	}
	return (NULL);
}

void    launch(t_philo *philo)
{
	int		i;
	int		status;
	pid_t	*pid;

	i = 0;
	pid = (pid_t *)malloc(sizeof(pid_t) * philo->state->np);
	while (i < philo->state->np)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			write (2, "Fork failed !\n", 15);
			exit (EXIT_FAILURE);
		}
		else if (pid[i] == 0)
		{
			philo->philo_id = i;
			philosopher(philo);
			usleep(1410065408);
		}
		i++;
	}
	waitpid(pid[i - 1], &status, WCONTINUED);
}

int		init_sem(t_philo *philo)
{
	sem_unlink("forks");
	philo->forks = sem_open("forks", O_CREAT, 0644, 0);
	sem_unlink("eating");
	philo->eating = sem_open("eating", O_CREAT, 0644, 0);
	sem_unlink("write");
	philo->write = sem_open("write", O_CREAT, 0644, 0);
	return(1);
}

int main(int argc, char *argv[])
{
	t_state *state;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
	{
		printf ("Philo takes at least five arguments !\n");
		return (0);
	}
	else
	{
		state = (t_state *)malloc(sizeof(t_state));
		philo = (t_philo *)malloc(sizeof(t_philo));
		if (!store_args(state, argv))
			return (0);
		if (!is_valid_args(state, argv))
			return (0);
		philo->state = state;
		if (!init_sem(philo))
			return (0);
		launch(philo);
	}
	return (1);
}
