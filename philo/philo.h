/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:32:39 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 16:51:57 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ******** Allowed functions ********

// memset
#include <string.h>

// printf
#include <stdio.h>

// malloc, free
#include <stdlib.h>

// write, usleep
#include <unistd.h>

// gettimeofday
#include <sys/time.h>

// pthread_create, pthread_detach, pthread_join, pthread_mutex_init
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
#include <pthread.h>

// ******** Custom structs ********

typedef struct s_simulation
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times;
	int				result_code;

	pthread_mutex_t	print_mtx;
	struct s_philo	*philos;
	int				sb_died;
	void	(*actions[3])(struct s_philo *);

}	t_simulation;

typedef struct s_philo
{
	t_simulation	*info;
	pthread_t		thread_id;
	pthread_mutex_t	fork_mtx;
	int	id;
	int	n_eat;
	int	state;
	int	l_meal;
}	t_philo;


// ******** Custom functions ********

// Actions
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);

void	print_state(t_philo *philo, char *msg);


void	end_simulation(t_simulation *info);
int		error(int error_code);
int		ft_atoi(char *str);
int		init_simulation(t_simulation *info);

void	*live(void *p);

long	now(void);
int		proccess_args(t_simulation *info, int argc, char **argv);
int		set_natural(char *str, int *natural);

// ******** Custom values ********

# define TRUE 1
# define FALSE 0

# define PHEUDO_INFINITE -1

// Philosopher's states
# define EATING 0
# define THINKING 1
# define SLEEPING 2

// Result values
# define SUCCESS 0
# define ERROR_ARGS_CODE 1
# define ERROR_NANATURAL_CODE 2
# define ERROR_MALLOC_CODE 3

// ******** Custom messages ********

// Error messages
# define ERROR_ARGS "./philo <philos> <t_d1ie> <t_eat> <t_sleep> [times]\n"
# define ERROR_NANATURAL "All arguments must be positive integers > 0\n"
# define ERROR_MALLOC "\n"

// States
# define FORK_MSG "[%04d] philo %d has taken a fork.\n"
# define EAT_MSG "[%04d] philo %d is eating.\n"
# define THINK_MSG "[%04d] philo %d is thinking.\n"
# define SLEEP_MSG "[%04d] philo %d is sleeping.\n"
# define DIE_MSG "[%04d] philo %d has died.\n"

// ******** Custom colors ********

# define NC "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define TITLE "\033[38;5;33m"

#endif