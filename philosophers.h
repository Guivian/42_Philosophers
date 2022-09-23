/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:20:27 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/23 18:55:23 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos{
	short			id;
	short			eating_id;
	short			times_eaten;
	pthread_t		philo;
	pthread_mutex_t	fork;
}	t_philos;

typedef struct s_vars{
	short			n_philo;
	short			n_meals;
	short			dead_or_alive;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	pthread_mutex_t	eating;
	pthread_mutex_t	check_death;
	t_philos		*philos;
}	t_vars;

//validate_args.c
void	validate_args(int argc, char **argv);
void	check_valid_arg(char **str);
void	validate_positive_numbers(void);

//convert_args.c
void	convert_argv(char **argv);
void	init(void);

//utils.c
int		char_to_int(char *str);

//structs.c
t_vars	*vars(void);

//philosophers.c
void	thread_handling(void);
void	take_forks(int i);
void	release_forks(int i);
void	sleep_and_think(int i);

//time_management.c
long	timestamp(void);
void	my_usleep(long long time);

#endif
