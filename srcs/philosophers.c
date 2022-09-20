/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:35:09 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/19 18:43:34 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat_or_die(void *philo_id)
{
	int		i;
	long	last_meal;

	i = *(int *)philo_id + 1;
	last_meal = 0;
	if (i % 2 != 0)
		usleep(vars()->time_to_sleep * 1000);
	while (1)
	{
		if (pthread_mutex_lock(&vars()->forks[i - 1]) == 0)
			printf("%li %i grabbed a fork\n", timestamp() - vars()->start_time, i);
		if (i == 1)
		{
			if (pthread_mutex_lock(&vars()->forks[i]) == 0)
				printf("%li %i grabbed a fork\n", timestamp() - vars()->start_time, i);
		}
		else
		{
			if (pthread_mutex_lock(&vars()->forks[i - 2]) == 0)
				printf("%li %i grabbed a fork\n", timestamp() - vars()->start_time, i);
		}
		if (timestamp() - vars()->start_time >= last_meal + vars()->time_to_die)
		{
			printf("%li %i is dead\n", timestamp() - vars()->start_time, i);
			exit(EXIT_FAILURE);
		}
		printf("%li %i is eating\n", timestamp() - vars()->start_time, i);
		usleep(vars()->time_to_eat * 1000);
		last_meal = timestamp() - vars()->start_time;
		pthread_mutex_unlock(&vars()->forks[i - 1]);
		printf("%li %i dropped a fork\n", timestamp() - vars()->start_time, i);
		if (i == 1)
		{
			if (pthread_mutex_unlock(&vars()->forks[i]) == 0)
				printf("%li %i dropped a fork\n", timestamp() - vars()->start_time, i);
		}
		else
		{
			if (pthread_mutex_unlock(&vars()->forks[i - 2]) == 0)
				printf("%li %i dropped a fork\n", timestamp() - vars()->start_time, i);
		}
		printf("%li %i is sleeping\n", timestamp() - vars()->start_time, i);
		usleep(vars()->time_to_sleep * 1000);
		printf("%li %i is thinking\n", timestamp() - vars()->start_time, i);
		if (i % 2 != 0)
			usleep(((vars()->time_to_eat * 2) - vars()->time_to_sleep) * 1000);
	}
	return (NULL);
}

void	thread_handling(void)
{
	int	i;

	i = -1;
	while (++i < vars()->n_philo)
		pthread_mutex_init(&vars()->forks[i], NULL);
	i = -1;
	vars()->start_time = timestamp();
	while (++i < vars()->n_philo)
	{
		vars()->philo_id = malloc(sizeof(int));
		*vars()->philo_id = i;
		pthread_create(&vars()->philos[i], NULL, &eat_or_die, \
		vars()->philo_id);
	}
	i = -1;
	while (++i < vars()->n_philo)
		pthread_join(vars()->philos[i], NULL);
}
