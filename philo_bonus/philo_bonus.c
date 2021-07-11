/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:16:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/07/11 21:42:03 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philo *philo)
{
	print_state(TAKE_FORK, philo);
	print_state(TAKE_FORK, philo);
}

void	start_eat(t_philo *philo)
{
	print_state(EAT, philo);
}

void	go_to_sleep(t_philo *philo)
{
	print_state(SLEEP, philo);
}

void	think(t_philo *philo)
{
	print_state(THINK, philo);
}

void	*philosopher(t_philo *philo)
{
	while (1)
	{
		philo->state->time_start = calculate_timestamp();
		take_forks(philo);
		start_eat(philo);
		go_to_sleep(philo);
		think(philo);
		usleep(100);
	}
	return (NULL);
}

void    launch(t_state *state)
{
	int i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * state->np);
	i = 0;
	while (i < state->np)
	{
		state->pid[i] = fork();
		if (state->pid[i] < 0)
			printf ("Error !\n");
		else if (state->pid[i] == 0)
		{
			philo[i].philo_id = i;
			philo[i].state = state;
			philo[i].last_meal = calculate_timestamp();
			philo[i].times_philo_ate = 0;
			philosopher(&philo[i]);
		}
		i++;
	}
}

int		init_sem(t_state *state)
{
	sem_unlink("forks");
	state->forks = sem_open("forks", O_CREAT, 0644, 0);
	sem_unlink("eating");
	state->eating = sem_open("eating", O_CREAT, 0644, 0);
	sem_unlink("write");
	state->write = sem_open("write", O_CREAT, 0644, 0);
	return(1);
}

int main(int argc, char *argv[])
{
	t_state *state;
	int		status;

	if (argc < 5 || argc > 6)
		printf ("Philo takes at least five arguments !\n");
	else
	{
		state = (t_state *)malloc(sizeof(t_state));
		if (!get_args(state, argv))
			return (0);
		if (!init_sem(state))
			return (0);
		launch(state);
		waitpid(state->pid[state->np - 1], &status, WCONTINUED);
	}
	return (1);
}
