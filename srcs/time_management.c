/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:06:57 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/21 16:23:00 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	timestamp(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000;
	ms += tv.tv_usec / 1000;
	return (ms);
}

void	my_usleep(long long time)
{
	int	i;

	i = 0;
	while (i < time)
	{
		usleep(10);
		i += 10;
	}
}
