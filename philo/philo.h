/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:32:39 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/28 22:18:27 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// ******** Allowed functions ********

// memset
# include <string.h>

// printf
# include <stdio.h>

// malloc, free
# include <stdlib.h>

// write, usleep
# include <unistd.h>

// gettimeofday
# include <sys/time.h>

// pthread_create, pthread_detach, pthread_join, pthread_mutex_init
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>

// ******** Custom values ********
# define PHEUDO_INFINITE -1

// Booleans
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

# define INVALID -1

// Philosopher's states
typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2
}	t_philo_state;

typedef enum e_philo_result
{
	SUCCESS = 0,
	ERROR_ARGS_CODE = 1,
	ERROR_NANATURAL_CODE = 2,
	ERROR_MALLOC_CODE = 3
}	t_philo_result;

// ******** Custom messages ********

// Error messages
# define ERROR_ARGS "./philo <philos> <t_die> <t_eat> <t_sleep> [times]\n"
# define ERROR_NANATURAL "All arguments must be positive integers > 0.\n"
# define ERROR_MALLOC "Malloc failed.\n"

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

# ifdef DEBUG_ON
#  define DEBUG 1
#  define TAKE_FORK_MSG "[\033[1;33m%08ld\033[0m] %d has taken a fork   (%d).\n"
#  define EAT_MSG   "[\033[1;33m%08ld\033[0m] %d is \033[1;33meating\033[0m.\n"
#  define SLEEP_MSG "[\033[1;33m%08ld\033[0m] %d is \033[1;34msleeping\033[0m.\n"
#  define THINK_MSG "[\033[1;33m%08ld\033[0m] %d is \033[1;32mthinking\033[0m.\n"
#  define DIE_MSG   "[\033[1;33m%08ld\033[0m] %d \033[1;31mdied\033[0m.\n"
// -----------
#  define START_MSG ""
#  define RETURN_FORK_MSG "[\033[1;33m%08ld\033[0m] %d has dropped a fork (%d).\n"
#  define END_MSG ""
# else
#  define DEBUG 0
#  define TAKE_FORK_MSG "%011ld %d has taken a fork\n"
#  define EAT_MSG       "%011ld %d is eating\n"
#  define SLEEP_MSG     "%011ld %d is sleeping\n"
#  define THINK_MSG     "%011ld %d is thinking\n"
#  define DIE_MSG       "%011ld %d died\n"
// -----------
#  define START_MSG ""
#  define RETURN_FORK_MSG "%ld%d%d"
#  define END_MSG ""
# endif

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
	void			(*actions[3])(struct s_philo *);
}	t_simulation;

typedef struct s_philo
{
	t_simulation	*info;
	pthread_t		thread_id;
	pthread_mutex_t	fork_mtx;
	int				id;
	int				n_eat;
	t_philo_state	state;
	long			l_meal;
}	t_philo;

// ******** Custom functions ********

// Simulation
t_philo_result	proccess_args(t_simulation *info, int argc, char **argv);
t_philo_result	init_simulation(t_simulation *info);
void			start_simulation(t_simulation *inf);
void			end_simulation(t_simulation *info);

// Philo
void			*live(void *p);
t_bool			simulation_ended(t_philo *philo);

// Actions
void			philo_eat(t_philo *philo);
void			philo_think(t_philo *philo);
void			philo_sleep(t_philo *philo);

// Forks
void			take_forks(t_philo *philo);
void			return_fork(t_philo *philo, int fork_id);
void			return_forks(t_philo *philo);
void			drop_all_forks(t_simulation *info);

// Print
t_philo_result	error(t_philo_result error_code);
void			print_state(t_philo *philo, char *msg);

// Tools
t_bool			died(t_philo *philo);
long			now(void);
long			ft_getmillis(t_philo *philo);
void			delay(long ms);
int				ft_atoi(char *str);
t_philo_result	set_natural(char *str, int *natural);

#endif
