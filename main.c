/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:57:40 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/08 14:53:39 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_args			*args;

	if (validate_args(argc, argv) == 0)
		return (0);
	args = convert_argv(argv);
	if (startup_philosophers(args) == 0)
		return (0);
	return (1);
}

