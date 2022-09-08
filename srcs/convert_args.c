/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:39:23 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/08 14:44:33 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_args	*convert_argv(char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (args == NULL)
		return (NULL);
	args->n_philo = char_to_int(argv[1]);
	args->time_to_die = char_to_int(argv[2]);
	args->time_to_eat = char_to_int(argv[3]);
	args->time_to_sleep = char_to_int(argv[4]);
	if (argv[5])
		args->n_meals = char_to_int(argv[5]);
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
