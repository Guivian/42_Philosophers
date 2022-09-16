/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:57:40 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/16 11:19:42 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*func(void *args);

int	main(int argc, char **argv)
{
	t_vars			*vars;

	if (validate_args(argc, argv) == 0)
		return (0);
	vars = convert_argv(argv);
	if (vars == NULL)
		return (0);
	thread_handling(vars);
	return (1);
}
