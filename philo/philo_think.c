/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:07:40 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/28 21:49:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Function to simulate the thinking of a philosopher.
 * 
 * @param philo Philosopher to simulate.
 */
void	philo_think(t_philo *philo)
{
	print_state(philo, THINK_MSG);
	philo->state = SLEEPING;
}
