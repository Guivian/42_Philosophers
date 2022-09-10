/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:35:09 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/08 18:18:01 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*test(void	*args)
{
	(void)args;
	printf("Hello from thread");
	return (NULL);
}

int	startup_philosophers(t_args *args)
{
	pthread_t	*philosophers;

	args->forks.forks = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	if (args->forks.forks == NULL)
		return (0);
	philosophers = malloc(sizeof(pthread_t) * args->n_philo);
	if (philosophers == NULL)
		return (0);
	args->philo_id = -1;
	while (++args->philo_id < args->n_philo)
		pthread_mutex_init(&args->forks.forks[args->philo_id], NULL);
	args->philo_id = -1;
	while (++args->philo_id < args->n_philo)
		pthread_create(&philosophers[args->philo_id], NULL, test, NULL);
	args->philo_id = -1;
	while (++args->philo_id < args->n_philo)
		pthread_join(philosophers[args->n_philo], NULL);
	return (1);
}

void	*philos(void *args)
{
	t_args	*new_args;

	new_args = (t_args *)args;
	if (new_args->philo_id == 1)	
		usleep(new_args->time_to_sleep);
	grab_fork(new_args, new_args->philo_id);
	if (new_args->philo_id == 1)
		grab_fork(new_args, new_args->n_philo);
	else
		grab_fork(new_args, new_args->philo_id - 1);
	printf("Philosopher %i is eating.\n", new_args->philo_id);
	usleep(new_args->time_to_eat);
	lay_forks_down(new_args, new_args->philo_id, new_args->philo_id - 1);
	printf("Philosopher %i is sleaping.\n", new_args->philo_id);
	usleep(new_args->time_to_sleep);
	printf("Philosopher %i is thinking.\n", new_args->philo_id);
	return (NULL);
}

void	grab_fork(t_args *args, int fork)
{
	pthread_mutex_lock(&args->forks.forks[fork]);
	printf("Philosopher %i grabbed a fork.\n", args->philo_id);
}

void	lay_forks_down(t_args *args, int right, int left)
{
	pthread_mutex_unlock(&args->forks.forks[right]);
	if (args->philo_id == 1)
		pthread_mutex_unlock(&args->forks.forks[args->n_philo]);
	else
		pthread_mutex_unlock(&args->forks.forks[left]);
}
