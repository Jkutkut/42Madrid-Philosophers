/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:32:39 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 23:36:59 by jre-gonz         ###   ########.fr       */
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

typedef struct s_philo
{
	int	id;
}	t_philo;


typedef struct s_main
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times;
	int				result_code;

	pthread_mutex_t	print_mtx;
	t_philo			*philos;
	int				*sb_died;

} t_main;


// ******** Custom functions ********

int	error(int error_code);
int	ft_atoi(char *str);
int	proccess_args(t_main *info, int argc, char **argv);
int	set_natural(char *str, int *natural);

// ******** Custom values ********

# define TRUE 1
# define FALSE 0

# define PHEUDO_INFINITE -1

// Result values
# define SUCCESS 0
# define ERROR_ARGS_CODE 1
# define ERROR_NANATURAL_CODE 2
# define ERROR_MALLOC_CODE 3

// ******** Custom messages ********

# define ERROR_ARGS "./philo <philos> <t_d1ie> <t_eat> <t_sleep> [times]\n"
# define ERROR_NANATURAL "All arguments must be positive integers > 0\n"

// ******** Custom colors ********

# define NC "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define TITLE "\033[38;5;33m"

#endif