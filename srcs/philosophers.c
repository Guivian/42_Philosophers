/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:35:09 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/21 16:24:32 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat_or_die(void *philo_id)
{
	int			i;
	long long	last_meal;

	i = *(int *)philo_id + 1;
	last_meal = 0;
//	if (i % 2 == 0)
//		usleep(vars()->time_to_sleep * 1000);
	while (1)
	{
		take_forks(i);
		if (timestamp() - vars()->start_time >= last_meal + vars()->time_to_die)
		{
			printf("%lld %i is dead\n", timestamp() - vars()->start_time, i);
			exit(EXIT_FAILURE);
		}
		printf("%lld %i is eating\n", timestamp() - vars()->start_time, i);
		my_usleep(vars()->time_to_eat * 1000);
		last_meal = timestamp() - vars()->start_time;
		release_forks(i);
		sleep_and_think(i);
	}
	return (NULL);
}

void	take_forks(int i)
{
	if (pthread_mutex_lock(&vars()->forks[i - 1]) == 0)
		printf("%lld %i grabbed a fork\n", timestamp() \
		- vars()->start_time, i);
	if (vars()->n_philo == 1)
	{
		my_usleep(vars()->time_to_die * 1000);
		printf("%lld %d is dead\n", timestamp() - vars()->start_time, 1);
		exit(EXIT_FAILURE);
	}
	if (i == 1)
	{
		if (pthread_mutex_lock(&vars()->forks[i]) == 0)
			printf("%lld %i grabbed a fork\n", timestamp() - \
			vars()->start_time, i);
	}
	else
	{
		if (pthread_mutex_lock(&vars()->forks[i - 2]) == 0)
			printf("%lld %i grabbed a fork\n", timestamp() - \
			vars()->start_time, i);
	}
}

void	release_forks(int i)
{
	pthread_mutex_unlock(&vars()->forks[i - 1]);
	printf("%lld %i dropped a fork\n", timestamp() - vars()->start_time, i);
	if (i == 1)
	{
		if (pthread_mutex_unlock(&vars()->forks[i]) == 0)
			printf("%lld %i dropped a fork\n", timestamp() - \
			vars()->start_time, i);
	}
	else
	{
		if (pthread_mutex_unlock(&vars()->forks[i - 2]) == 0)
			printf("%lld %i dropped a fork\n", timestamp() - \
			vars()->start_time, i);
	}
}

void	sleep_and_think(int i)
{
	printf("%lld %i is sleeping\n", timestamp() - vars()->start_time, i);
	my_usleep(vars()->time_to_sleep * 1000);
	printf("%lld %i is thinking\n", timestamp() - vars()->start_time, i);
	//if (i % 2 != 0)
	//	usleep(((vars()->time_to_eat * 2) - vars()->time_to_sleep) * 1000);
}

void	thread_handling(void)
{
	int	i;

	i = -1;
	pthread_mutex_init(&vars()->dead_or_alive, NULL);
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
