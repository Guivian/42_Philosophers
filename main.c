/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:57:40 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/08 19:00:22 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*func(void *args);

int	main(int argc, char **argv)
{
	pthread_t		*test;
	t_args			*args;

	if (validate_args(argc, argv) == 0)
		return (0);
	args = convert_argv(argv);
	test = malloc(sizeof(pthread_t) * args->n_philo);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	args->philo_id = -1;
	while (++args->philo_id < args->n_philo)
		pthread_mutex_init(&args->forks[args->philo_id], NULL);
	args->philo_id = -1;
	while (++args->philo_id < args->n_philo)
		pthread_create(&test[args->philo_id], NULL, func, args);
	args->philo_id = -1;
	while (++args->philo_id < args->n_philo)
		pthread_join(test[args->philo_id], NULL);
	// if (startup_philosophers(args) == 0)
	// 	return (0);
	return (1);
}

void	*func(void *args)
{
	t_args	*new_args;

	new_args = (t_args *)args;
	pthread_mutex_lock(&new_args->forks[new_args->n_philo]);
	printf("Hello from thread %i\n", new_args->philo_id);
	pthread_mutex_unlock(&new_args->forks[new_args->philo_id]);
	return (NULL);
}
