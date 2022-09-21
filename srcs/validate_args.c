/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:27:28 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/21 13:55:11 by lbarbosa         ###   ########.fr       */
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
