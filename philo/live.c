/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:16:00 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 20:15:26 by jre-gonz         ###   ########.fr       */
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
	philo->l_meal = now();
	if (philo->id % 2)
		delay(philo->info->t_sleep >> 1);
	while (1)
	{
		if (simulation_ended(philo))
			break;
		if (now() - philo->l_meal > philo->info->t_die)
		{
			philo->info->sb_died = TRUE;
			print_state(philo, DIE_MSG, DIE_COLOR);
			drop_all_forks(philo->info);
			break;
		}
		philo->info->actions[philo->state](philo);
	}
	print_philo_msg(philo, END_MSG);
	return (NULL);
}