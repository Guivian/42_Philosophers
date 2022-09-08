/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:20:27 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/08 15:46:23 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_forks{
	pthread_mutex_t	*forks;
}	t_forks;

typedef struct s_args{
	int				n_philo;
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_meals;
	t_forks			forks;
}	t_args;

//validate_args.c
int		validate_args(int argc, char **argv);
int		check_valid_arg(char **str);

//convert_args.c
t_args	*convert_argv(char **argv);
int		char_to_int(char *str);

//philosophers.c
int		startup_philosophers(t_args *args);
void	*philos(void *args);
void	grab_fork(t_args *args, int fork);
void	lay_forks_down(t_args *args, int right, int left);

#endif
