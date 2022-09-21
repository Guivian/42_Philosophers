/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:20:27 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/21 16:23:54 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_vars{
	int				n_philo;
	int				*philo_id;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				n_meals;
	long long		start_time;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_or_alive;
}	t_vars;

//validate_args.c
void	validate_args(int argc, char **argv);
void	check_valid_arg(char **str);

//convert_args.c
void	convert_argv(char **argv);
int		char_to_int(char *str);
t_vars	*vars(void);
void	init_struct(void);
void	validate_positive_numbers(void);

//philosophers.c
void	thread_handling(void);
void	take_forks(int i);
void	release_forks(int i);
void	sleep_and_think(int i);

//timestamps.c
long	timestamp(void);
void	my_usleep(long long time);

#endif
