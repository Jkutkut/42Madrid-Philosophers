/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:16:00 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 18:32:05 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_philo_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print_mtx);
	printf(msg, TITLE, philo->id, NC, YELLOW, NC);
	pthread_mutex_unlock(&philo->info->print_mtx);
}

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
	print_philo_msg(philo, START_MSG);
	while (1)
	{
		if (simulation_ended(philo))
			break;
		philo->info->actions[philo->state](philo);
	}
	print_philo_msg(philo, END_MSG);
	return (NULL);
}