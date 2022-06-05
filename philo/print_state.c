/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:02:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 17:58:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints the state of the philosopher.
 * 
 * @param philo Philosopher to print.
 * @param msg Message to print.
 */
void	print_state(t_philo *philo, char *msg)
{
	long time_now;

	pthread_mutex_lock(&philo->info->print_mtx);
	time_now = now();
	printf(msg, time_now - philo->info->t0, philo->id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}