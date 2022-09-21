/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:39:23 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/21 14:52:17 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	convert_argv(char **argv)
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
		exit(EXIT_FAILURE);
	}
	vars()->n_philo = char_to_int(argv[1]);
	vars()->time_to_die = char_to_int(argv[2]);
	vars()->time_to_eat = char_to_int(argv[3]);
	vars()->time_to_sleep = char_to_int(argv[4]);
	if (argv[5])
		vars()->n_meals = char_to_int(argv[5]);
	validate_positive_numbers();
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

void	validate_positive_numbers(void)
{
	if (vars()->n_philo < 1)
	{
		write(1, "Invalid argument\nPlease test with at least 1 philosopher\n", 58);
		exit(EXIT_FAILURE);
	}
	if (vars()->time_to_die < 60 || \
	vars()->time_to_eat < 60 || \
	vars()->time_to_sleep < 60)
	{
		write(1, "Invalid argument\nPlease test with at least 60ms\n", 48);
		exit(EXIT_FAILURE);
	}
	if (vars()->n_meals < 1)
	{
		write(1, "Invalid argument\n", 18);
		write(1, "If number_of_meals is specified, give it a value greater than 0\n", 65);
		exit(EXIT_FAILURE);
	}
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
