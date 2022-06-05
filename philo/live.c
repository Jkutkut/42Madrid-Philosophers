/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:16:00 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 17:16:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Simulates the live of the given philosopher.
 * 
 * @param p Philosopher to simulate.
 * @return void* NULL.
 */
void	*live(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	printf("Philosopher %d is alive\n", philo->id);
	while (1)
	{
		if (simulation_ended(philo))
			break;
		philo->info->actions[philo->state](philo);
	}
	printf("Philosopher %d's simulation ended\n", philo->id);
	return (NULL);
}