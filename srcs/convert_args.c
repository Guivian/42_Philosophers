/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:39:23 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/18 12:53:32 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	convert_argv(char **argv)
{
	int	allocation;

	allocation = 0;
	init_struct();
	vars()->forks = malloc(sizeof(pthread_mutex_t) * char_to_int(argv[1]));
	if (vars()->forks == NULL)
		allocation = -1;
	vars()->philos = malloc(sizeof(pthread_t) * char_to_int(argv[1]));
	if (vars()->philos == NULL)
		allocation = -1;
	vars()->philo_id = malloc(sizeof(int) * char_to_int(argv[1]));
	if (vars()->philo_id == NULL)
		allocation = -1;
	if (allocation == -1)
	{
		write(1, "Error occured during memory allocation\n", 40);
	}
	vars()->n_philo = char_to_int(argv[1]);
	vars()->time_to_die = char_to_int(argv[2]);
	vars()->time_to_eat = char_to_int(argv[3]);
	vars()->time_to_sleep = char_to_int(argv[4]);
	if (argv[5])
		vars()->n_meals = char_to_int(argv[5]);
	if (validate_positive_numbers() == 0)
		return (0);
	return (1);
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

int	validate_positive_numbers(void)
{
	if (vars()->n_philo == 0 || \
	vars()->time_to_die == 0 || \
	vars()->time_to_eat == 0 || \
	vars()->time_to_sleep == 0 || \
	vars()->n_meals ==0)
	{
		write(1, "Invalid argument\nOnly positive numbers allowed\n", 48);
		return (0);
	}
	return (1);
}

void	init_struct(void)
{
	vars()->forks = NULL;
	vars()->philos = NULL;
	vars()->philo_id = NULL;
	vars()->n_philo = 0;
	vars()->time_to_die = 0;
	vars()->time_to_eat = 0;
	vars()->time_to_sleep = 0;
	vars()->n_meals = 1;
	vars()->start_time = 0;
}

t_vars	*vars(void)
{
	static t_vars	vars;
	return (&vars);
}
