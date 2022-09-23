/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:39:23 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/23 19:39:50 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	convert_argv(char **argv)
{
	vars()->n_philo = char_to_int(argv[1]);
	vars()->time_to_die = char_to_int(argv[2]);
	vars()->time_to_eat = char_to_int(argv[3]);
	vars()->time_to_sleep = char_to_int(argv[4]);
	vars()->dead_or_alive = 0;
	if (argv[5])
		vars()->n_meals = char_to_int(argv[5]);
	else
		vars()->n_meals = 1;
	validate_positive_numbers();
}

void	init(void)
{
	int	i;

	i = -1;
	vars()->philos = malloc(sizeof(t_philos) * vars()->n_philo);
	if (vars()->philos == NULL)
		exit(EXIT_FAILURE);
	while (++i < vars()->n_philo)
		pthread_mutex_init(&vars()->philos[i].fork, NULL);
	pthread_mutex_init(&vars()->eating, NULL);
	pthread_mutex_init(&vars()->check_death, NULL);
}
