/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:06:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/28 21:51:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Function to simulate the sleep of a philosopher.
 * 
 * @param philo Philosopher to simulate.
 */
void	philo_sleep(t_philo *philo)
{
	if (DEBUG)
		print_state(philo, SLEEP_MSG, SLEEP_COLOR);
	else
		print_state_classic(philo, SLEEP_MSG_CLASSIC);
	delay(philo->info->t_sleep);
	philo->state = EATING;
}
