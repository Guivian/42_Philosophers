/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:57:40 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/21 14:51:34 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*func(void *args);

int	main(int argc, char **argv)
{
	validate_args(argc, argv);
	convert_argv(argv);
	thread_handling();
	return (1);
}
