/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:51:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 13:11:33 by jre-gonz         ###   ########.fr       */
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

// pthread_create, pthread_detach, pthread_join
# include <pthread.h>

// TODO em_open, sem_close, sem_post, sem_wait, sem_unlink

// ******** Custom values ********
# define PHEUDO_INFINITE -1

// Booleans
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

# define INVALID -1

// ******** Custom enums ********

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

// ******** Custom structs ********

typedef struct s_simulation
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_times;
	int				result_code;
	long			t0;
	// pthread_mutex_t	print_mtx; // TODO Handle with sem
	struct s_philo	*philos;
	int				sb_died;
	void			(*actions[3])(struct s_philo *);
}	t_simulation;

typedef struct s_philo
{
	t_simulation	*info;
	pthread_t		thread_id;
	// pthread_mutex_t	fork_mtx; // TODO Handle with sem
	int				id;
	unsigned int	n_eat;
	t_philo_state	state;
	long			l_meal;
}	t_philo;

// ******** Custom messages ********

// Error messages
# define ERROR "philo_bonus \033[1;31merror\033[0m:\n  "
# define ERROR_ARGS "./philo_bonus <philos> <t_die> <t_eat> <t_sleep> [times]\n"
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
#  define TAKE_FORK_MSG "[\033[1;33m%08ld\033[0m] %d has taken a fork   (%d).\n" // TODO
#  define EAT_MSG   "[\033[1;33m%08ld\033[0m] %d is \033[1;33meating\033[0m.\n"
#  define SLEEP_MSG "[\033[1;33m%08ld\033[0m] %d is \033[1;34msleeping\033[0m.\n"
#  define THINK_MSG "[\033[1;33m%08ld\033[0m] %d is \033[1;32mthinking\033[0m.\n"
#  define DIE_MSG   "[\033[1;33m%08ld\033[0m] %d \033[1;31mdied\033[0m.\n"
// -----------
#  define START_MSG ""
#  define RETURN_FORK_MSG "[\033[1;33m%08ld\033[0m] %d has dropped a fork (%d).\n" // TODO
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

// ******** Custom functions ********

// ******** Simulation ********

/**
 * @brief Updates the main struct with the arguments given.
 * 
 * The code updates the first 5 variables on the struct as they're ints.
 * 
 * @param info The main struct to update.
 * @param argc argc from main.
 * @param argv argv from main.
 * @return int SUCCESS if everything went well, ERROR code otherwise.
 */
t_philo_result	proccess_args(t_simulation *info, int argc, char **argv);

// TODO

// ******** Philo ********
// ******** Actions ********
// ******** Forks ********
// ******** Print ********

/**
 * @brief Prints the error message defined by the error code.
 * 
 * If success code is given, nothing is printed.
 * 
 * @param error_code Error code.
 * @return The input given.
 */
t_philo_result	error(t_philo_result error_code);

// TODO

// ******** Tools ********

// TODO

/**
 * @brief Converts a string to an unsigned integer.
 * 
 * @param str String to convert.
 * @return Number representing the string.
 */
unsigned int	ft_atoi(char *str);

/**
 * @brief Updates the given int value with the given string using ft_atoi.
 * 
 * @param str String to convert.
 * @param natural Pointer to the int to update.
 * @return int SUCCESS if successful, else ERROR_NANATURAL_CODE.
 */
t_philo_result	set_natural(char *str, int *natural);

#endif