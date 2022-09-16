/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:57:40 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/16 20:38:48 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*func(void *args);

int	main(int argc, char **argv)
{
	if (validate_args(argc, argv) == 0)
		return (0);
	if (convert_argv(argv) == 0)
		return (0);
	thread_handling();
	return (1);
}
