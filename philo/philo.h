/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:32:39 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 19:31:13 by jre-gonz         ###   ########.fr       */
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

	long			t0;

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

void	print_state(t_philo *philo, char *msg, char *color);

void	delay(long ms);
void	end_simulation(t_simulation *info);
int		error(int error_code);
int		ft_atoi(char *str);
int		init_simulation(t_simulation *info);
void	*live(void *p);
long	now(void);
int		proccess_args(t_simulation *info, int argc, char **argv);
int		set_natural(char *str, int *natural);
int		simulation_ended(t_philo *philo);

// ******** Custom values ********

# define TRUE 1
# define FALSE 0

# define PHEUDO_INFINITE -1

// Philosopher's states
# define EATING 0
# define SLEEPING 1
# define THINKING 2

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
# define FORK_MSG  "[%s%05d%s] philo %d %shas taken a fork%s.\n"
# define EAT_MSG   "[%s%05d%s] philo %d %sis eating%s.\n"
# define THINK_MSG "[%s%05d%s] philo %d %sis thinking%s.\n"
# define SLEEP_MSG "[%s%05d%s] philo %d %sis sleeping%s.\n"
# define DIE_MSG   "[%s%05d%s] philo %d %shas died%s.\n"

# define START_MSG "Philosopher %s%d%s is %salive%s\n"
# define END_MSG "Philosopher %s%d%s's simulation %sended%s\n"

// ******** Custom colors ********

# define NC "\033[0m"
# define S_BG "\e[1;7m"
# define R_BG "\e[1;41m"
# define B_BG "\e[1;44m"
# define G_BG "\e[1;42m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define LRED "\033[1;31m"
# define LGREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define LBLUE "\033[1;34m"
# define TITLE "\033[38;5;33m"

// State colors
# define FORK_COLOR NC
# define EAT_COLOR YELLOW
# define THINK_COLOR LGREEN
# define SLEEP_COLOR LBLUE
# define DIE_COLOR RED

#endif