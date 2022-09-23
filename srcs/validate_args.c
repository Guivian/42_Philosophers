/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:27:28 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/22 19:10:29 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write(1, "Invalid number of arguments\n", 29);
		exit(EXIT_FAILURE);
	}
	check_valid_arg(argv);
}

void	check_valid_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (argv[i][0] == '+')
			j = 0;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Invalid argument\nOnly positive numbers allowed\n", 48);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	validate_positive_numbers(void)
{
	if (vars()->n_philo < 1)
	{
		write(1, "Invalid argument\n", 18);
		write(1, "Please test with at least 1 philosopher\n", 41);
		free(vars());
		exit(EXIT_FAILURE);
	}
	if (vars()->time_to_die < 60 || \
	vars()->time_to_eat < 60 || \
	vars()->time_to_sleep < 60)
	{
		write(1, "Invalid argument\nPlease test with at least 60ms\n", 48);
		free(vars());
		exit(EXIT_FAILURE);
	}
	if (vars()->n_meals < 1)
	{
		write(1, "Invalid argument\n", 18);
		write(1, "If number_of_meals is specified, ", 34);
		write(1, "give it a value greater than 0\n", 32);
		free(vars());
		exit(EXIT_FAILURE);
	}
}
