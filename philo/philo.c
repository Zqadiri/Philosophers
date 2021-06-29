/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:54:27 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/29 17:52:47 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

// * number_of_philosophers time_to_die
// * time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

// ! switch to ft_atoi

int	get_args(t_philo *philo, char **args)
{
	philo->np = atoi(args[1]);
	philo->tt_die = atoi(args[2]);
	philo->tt_eat = atoi(args[3]);
	philo->tt_sleep = atoi(args[4]);
	if (args[5] != NULL)
		philo->np = atoi(args[1]);
	return (1);
}

int counter;

void* trythis(void* arg)
{
    (void)arg;
	unsigned long i = 0;
	counter += 1;
	printf("\n Job %d has started\n", counter);

	for (i = 0; i < (0xFFFFFFFF); i++)
		;
	printf("\n Job %d has finished\n", counter);
	return NULL;
}

int		set_threads(t_philo *philo)
{
	
	int			error;
	pthread_t	tid[philo->np];
	int			i;

	i = 0;
	while (i < philo->np)
	{
		error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
		// pthread_join(tid[i], NULL);
		i++;
	}
	i = 0;
	while(i < philo->np)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (1);
}

int     main(int argc, char *argv[])
{
	t_philo philo;
	t_state state;

	if (argc < 5 || argc > 6)
		printf ("Philo takes at least five arguments !\n");
	else
	{
		if (!init(&philo, &state))
			return (0);
		if (!get_args(&philo, argv))
			return (0);
    	print_args(&philo, &state);
		
		// if (!set_threads(&philo, &state))
		// 	return (0);
	}
	return (1);
}