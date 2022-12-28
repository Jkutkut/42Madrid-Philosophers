/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:02:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/28 21:48:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints the state of the philosopher.
 * 
 * @param philo Philosopher to print.
 * @param msg Message to print.
 */
void	print_state(t_philo *philo, char *msg, char *color)
{
	pthread_mutex_lock(&philo->info->print_mtx);
	printf(msg, YELLOW, ft_getmillis(philo), NC, philo->id, color, NC);
	pthread_mutex_unlock(&philo->info->print_mtx);
}

/**
 * @brief Prints the state of the philosopher.
 * 
 * @param philo Philosopher to print.
 * @param msg Message to print.
 */
void	print_state_classic(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print_mtx);
	printf(msg, ft_getmillis(philo), philo->id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}
