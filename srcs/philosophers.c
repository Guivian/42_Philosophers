/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:35:09 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/16 15:53:02 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*routine(void	*vars)
{
	int	i;

	i = *(int *)vars;
	printf("Hello from Thread %d\n", i + 1);
	return (NULL);
}

void	thread_handling(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n_philo)
		pthread_mutex_init(&vars->forks[i], NULL);
	i = -1;
	while (++i < vars->n_philo)
	{
		vars->philo_id = malloc(sizeof(int));
		*vars->philo_id = i;
		pthread_create(&vars->philos[i], NULL, &routine, \
		vars);
	}
	i = -1;
	while (++i < vars->n_philo)
		pthread_join(vars->philos[i], NULL);
}
