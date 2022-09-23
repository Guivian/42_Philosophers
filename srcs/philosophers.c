/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:35:09 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/23 18:53:45 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat_or_die(void *id)
{
	int			*i;
	short		other_fork;

	i = (int *)id;
	other_fork = vars()->philos[i[0]].id - 1;
	while (1)
	{
		if (vars()->philos[i[0]].id == vars()->n_philo)
		{
			vars()->philos[i[0]].eating_id = vars()->philos[i[0]].id - 1;
			other_fork = 0;
		}
		pthread_mutex_lock(&vars()->philos[vars()->philos[i[0]].eating_id].fork);
		printf("%lld %i grabbed a fork\n", timestamp() \
		- vars()->start_time, i[0]);
		pthread_mutex_lock(&vars()->philos[other_fork].fork);
		printf("%lld %i grabbed a fork\n", timestamp() \
		- vars()->start_time, i[0]);
		pthread_mutex_lock(&vars()->eating);
		printf("%lld %i is eating\n", timestamp() \
		- vars()->start_time, i[0]);
		usleep(vars()->time_to_eat * 1000);
		vars()->philos[i[0]].times_eaten++;
		pthread_mutex_unlock(&vars()->eating);
		pthread_mutex_unlock(&vars()->philos[vars()->philos[i[0]].eating_id].fork);
		pthread_mutex_unlock(&vars()->philos[other_fork].fork);
		printf("%lld %i is sleeping\n", timestamp() \
		- vars()->start_time, i[0]);
		usleep(vars()->time_to_sleep * 1000);
		printf("%lld %i is thinking\n", timestamp() \
		- vars()->start_time, i[0]);
	}
	return (NULL);
}

void	thread_handling(void)
{
	int	i;

	i = -1;
	vars()->start_time = timestamp();
	while (++i < vars()->n_philo)
	{
		vars()->philos[i].id = i + 1;
		vars()->philos[i].eating_id = i + 1;
		vars()->philos[i].times_eaten = 0;
		pthread_create(&vars()->philos[i].philo, NULL, &eat_or_die, \
		&i);
	}
	i = -1;
	while (++i < vars()->n_philo)
		pthread_join(vars()->philos[i].philo, NULL);
	pthread_mutex_destroy(&vars()->eating);
	pthread_mutex_destroy(&vars()->check_death);
	i = -1;
	while (++i < vars()->n_philo)
		pthread_mutex_destroy(&vars()->philos[i].fork);
}
