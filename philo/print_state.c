/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:02:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/03/08 16:31:21 by jre-gonz         ###   ########.fr       */
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
	if (!simulation_ended(philo) || died(philo))
		printf(msg, YELLOW, ft_getmillis(philo), NC, philo->id + 1, color, NC);
	pthread_mutex_unlock(&philo->info->print_mtx);
}

/**
 * @brief Prints the state of the philosopher.
 * 
 * @param philo Philosopher to print.
 * @param msg Message to print.
 */
void	print_state_classic(t_philo *philo, char *msg)
{ // TODO update with normal version
	pthread_mutex_lock(&philo->info->print_mtx);
	printf(msg, ft_getmillis(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->info->print_mtx);
}
