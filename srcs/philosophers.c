/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:35:09 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/18 13:31:35 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat_or_die(void	*philo_id)
{
	int	i;

	i = *(int *)philo_id + 1;
	if (i % 2 != 0)
		usleep(vars()->time_to_sleep * 1000);
	while (1)
	{
		printf("%li %i is thinking\n", timestamp() - vars()->start_time, i);
		pthread_mutex_lock(&vars()->forks[i]);
		//printf("%li %i grabbed a fork\n", timestamp() - vars()->start_time, i);
		if (i == 1)
		{
			pthread_mutex_lock(&vars()->forks[i + 1]);
			//printf("%li %i grabbed a fork\n", timestamp() - vars()->start_time, i);
		}
		else
		{
			pthread_mutex_lock(&vars()->forks[i - 1]);
			//printf("%li %i grabbed a fork\n", timestamp() - vars()->start_time, i);
		}
		printf("%li %i is eating\n", timestamp() - vars()->start_time, i);
		usleep(vars()->time_to_eat * 1000);
		pthread_mutex_unlock(&vars()->forks[i]);
		if (i == 1)
			pthread_mutex_unlock(&vars()->forks[i + 1]);
		else
			pthread_mutex_unlock(&vars()->forks[i - 1]);
		printf("%li %i is sleeping\n", timestamp() - vars()->start_time, i);
		usleep(vars()->time_to_sleep * 1000);
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
