/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/08 17:53:58 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Function that simulates the eating of a philosopher.
 * 
 * @param philo Philosopher to make eat.
 */
void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	if (simulation_ended(philo))
		return return_forks(philo);
	print_state(philo, EAT_MSG, EAT_COLOR);
	philo->n_eat++;
	delay(philo->info->t_eat);
	philo->l_meal = now();
	return_forks(philo);
	philo->state = THINKING;
}
