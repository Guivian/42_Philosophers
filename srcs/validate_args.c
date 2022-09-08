/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:27:28 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/07 12:46:13 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write(1, "Invalid number of arguments\n", 29);
		return (0);
	}
	if (check_valid_arg(argv) == 0)
		return (0);
	return (1);
}

int	check_valid_arg(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				write(1, "Invalid argument\nOnly positive numbers allowed\n", 48);
				return (0);
			}
		}
	}
	return (1);
}
