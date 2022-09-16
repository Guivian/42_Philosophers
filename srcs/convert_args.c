/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:39:23 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/16 15:36:04 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_vars	*convert_argv(char **argv)
{
	t_vars	*args;

	args = malloc(sizeof(t_vars));
	if (args == NULL)
		return (NULL);
	args->forks = malloc(sizeof(pthread_mutex_t) * char_to_int(argv[1]));
	if (args->forks == NULL)
		return (NULL);
	args->philos = malloc(sizeof(pthread_t) * char_to_int(argv[1]));
	if (args->philos == NULL)
		return (NULL);
	args->philo_id = malloc(sizeof(int) * char_to_int(argv[1]));
	if (args->philo_id == NULL)
		return (NULL);
	args->n_philo = char_to_int(argv[1]);
	args->time_to_die = char_to_int(argv[2]);
	args->time_to_eat = char_to_int(argv[3]);
	args->time_to_sleep = char_to_int(argv[4]);
	if (argv[5])
		args->n_meals = char_to_int(argv[5]);
	//fill_philo_ids(args);
	return (args);
}

int	char_to_int(char *str)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (str[++i] >= '0' && str[i] <= '9')
		ret = (ret * 10) + (str[i] - '0');
	return (ret);
}

void	fill_philo_ids(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n_philo)
		vars->philo_id[i] = i + 1;
}
