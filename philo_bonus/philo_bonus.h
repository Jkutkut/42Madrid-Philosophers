/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:51:12 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/26 16:43:15 by jre-gonz         ###   ########.fr       */
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

// fork, waitpid, kill
# include <sys/types.h>
# include <sys/wait.h>

// sem_open, sem_close, sem_post, sem_wait, sem_unlink
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

// SIGKILL
# include <signal.h>

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
	ERROR_MALLOC_CODE = 3,
	ERROR_SEM_CODE = 4
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
	sem_t			*print_sem;
	sem_t			*forks_sem;
	struct s_philo	*philos;
	pid_t			*pids;
	int				sb_died;
	void			(*actions[3])(struct s_philo *);
}	t_simulation;

typedef struct s_philo
{
	t_simulation	*info;
	pthread_t		thread_id;
	int				id;
	unsigned int	n_eat;
	t_philo_state	state;
	long			l_meal;
}	t_philo;

// ******** Custom messages ********

#define SEM_FORKS "/forks"
#define SEM_PRINT "/print"

// Error messages
# define ERROR "philo_bonus \033[1;31merror\033[0m:\n  "
# define ERROR_ARGS "./philo_bonus <philos> <t_die> <t_eat> <t_sleep> [times]\n"
# define ERROR_NANATURAL "All arguments must be positive integers > 0.\n"
# define ERROR_MALLOC "Malloc failed.\n"
# define ERROR_SEM "Semaphore failed.\n"

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
#  define TAKE_FORK_MSG "[\033[1;33m%08ld\033[0m] %d has taken a fork.\n" // TODO
#  define EAT_MSG   "[\033[1;33m%08ld\033[0m] %d is \033[1;33meating\033[0m.\n"
#  define SLEEP_MSG "[\033[1;33m%08ld\033[0m] %d is \033[1;34msleeping\033[0m.\n"
#  define THINK_MSG "[\033[1;33m%08ld\033[0m] %d is \033[1;32mthinking\033[0m.\n"
#  define DIE_MSG   "[\033[1;33m%08ld\033[0m] %d \033[1;31mdied\033[0m.\n"
// -----------
#  define START_MSG ""
#  define RETURN_FORK_MSG "[\033[1;33m%08ld\033[0m] %d has dropped a fork.\n" // TODO
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

/**
 * @brief Creates all the necessary threads and logic to make the simulation.
 * 
 * @param inf Structure with all the information about the philosophers.
 * @return int SUCCESS if everything went well, ERROR code if there was any.
 */
t_philo_result	init_simulation(t_simulation *info);

/**
 * @brief Starts the simulation in all threads.
 * @param inf Simulation structure with all the information.
 */
void			start_simulation(t_simulation *inf);

/**
 * @brief Joins all the threads and frees all the allocated memory.
 * Note: pthread_join waits for all threads to end.
 * 
 * @param info Structure with all the information about the philosophers.
 */
void			end_simulation(t_simulation *info);

// ******** Philo ********

// TODO

/**
 * @brief Analyzes the simulation and determines if the simulation should end
 * for the given philosopher.
 * 
 * @param philo Philosopher to analyze.
 * @return TRUE if the simulation should end, FALSE otherwise.
 */
t_bool			simulation_ended(t_philo *philo);

// ******** Actions ********

/**
 * @brief Function that simulates the eating of a philosopher.
 * 
 * @param philo Philosopher to make eat.
 */
void			philo_eat(t_philo *philo);

/**
 * @brief Function to simulate the thinking of a philosopher.
 * 
 * @param philo Philosopher to simulate.
 */
void			philo_think(t_philo *philo);

/**
 * @brief Function to simulate the sleep of a philosopher.
 * 
 * @param philo Philosopher to simulate.
 */
void			philo_sleep(t_philo *philo);

// ******** Forks ********

/**
 * @brief Obtains the selected fork for the given philo.
 */
void			take_fork(t_philo *philo);

/**
 * @brief Returns to the table a fork.
 * 
 * @param philo Philosopher with the fork.
 */
void			return_fork(t_philo *philo);

// TODO

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

/**
 * @brief Prints the state of the philosopher.
 * 
 * @param philo Philosopher to print.
 * @param msg Message to print.
 */
void			print_state(t_philo *philo, char *msg);

// ******** Tools ********

/**
 * @brief Checks if the given philo has died.
 * 
 * @param philo t_philo The philosopher to check.
 * @returns true if it died, false otherwise.
 */
t_bool			died(t_philo *philo);

/**
 * @brief Custom function that returns the current time in milliseconds.
 * 
 * @return long Current time in milliseconds.
 */
long			now(void);

/**
 * @returns The time since the start of the simulation.
 */
long			ft_getmillis(t_philo *philo);

/**
 * @brief Custom function that waits the given amount of milliseconds.
 * The use of usleep is now good enough.
 *
 * @param ms Amount of milliseconds to wait.
 */
void			delay(long ms);

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
