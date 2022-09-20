/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:20:27 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/20 12:56:30 by lbarbosa         ###   ########.fr       */
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
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	long			start_time;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_or_alive;
}	t_vars;

//validate_args.c
int		validate_args(int argc, char **argv);
int		check_valid_arg(char **str);

//convert_args.c
int		convert_argv(char **argv);
int		char_to_int(char *str);
t_vars	*vars(void);
void	init_struct(void);
int		validate_positive_numbers(void);

//philosophers.c
void	thread_handling(void);

//timestamps.c
long	timestamp(void);

#endif
