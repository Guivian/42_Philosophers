#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include "philosophers.h"

#define PHILOS 5
#define DELAY 5000
#define FOOD 50

void	*philosopher(void *num);
void	grab_fork(int phil, int c, char *hand);
void	down_fork(int c1, int c2);
int		food_on_table(void);

int	main(int argc, char **argv)
{
	t_args	*args;

	if (validate_args(argc, argv) == 0)
		return (0);
	args = convert_argv(argv);
	pthread_mutex_init(&args->food_lock, NULL);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	args->philos = malloc(sizeof(pthread_t) * args->n_philo);
	for (args->philo_id = 0; args->philo_id < PHILOS; args->philo_id++)
		pthread_mutex_init(&args->forks[i], NULL);
	for (args->philo_id = 0; args->philo_id < PHILOS; args->philo_id++)
		pthread_create(&args->philos[i], NULL, philosopher, (void *)args);
	for (args->philo_id = 0; args->philo_id < PHILOS; args->philo_id++)
		pthread_join(args->philos[i], NULL);
	return (0);
}

void	*philosopher(void *num)
{
	int	id;
	int	i;
	int	left_fork;
	int	right_fork;
	int	f;

	id = (int)num;
	printf("Philosopher %d is done thinking and is now ready to eat.\n", id);
	right_fork = id;
	left_fork = id + 1;
	if (left_fork == PHILOS)
		left_fork = 0;
	while (f = food_on_table())
	{
		if (id == 1)
			sleep(sleep_seconds);
		grab_fork(id, right_fork, "right");
		grab_fork(id, left_fork, "left");
		printf("Philosopher %d is eating.\n", id);
		usleep(DELAY * (FOOD - f + 1));
		down_fork(left_fork, right_fork);
	}
	printf("Philosopher %d is done eating.\n", id);
	return (NULL);
}

int	food_on_table(void)
{
	static int	food = FOOD;
	int			myfood;

	pthread_mutex_lock(&food_lock);
	if (food > 0)
		food--;
	myfood = food;
	pthread_mutex_unlock(&food_lock);
	return (myfood);
}

void	grab_fork(int phil, int c, char *hand)
{
	pthread_mutex_lock(&forks[c]);
	printf("Philosopher %d grabbed the fork %d to his %s\n", phil, c, hand);
}

void	down_fork(int c1, int c2)
{
	pthread_mutex_unlock(&forks[c1]);
	pthread_mutex_unlock(&forks[c2]);
}
