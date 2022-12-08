/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:42:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/08 12:54:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Obtain the 2 forks needed to eat.
 * 
 * @param philo Philosopher that is trying to eat.
 */
void	take_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	pthread_mutex_lock(&philo->info->philos[id].fork_mtx);
	print_state(philo, FORK_MSG, FORK_COLOR);
	if (simulation_ended(philo))
	{
		pthread_mutex_unlock(&philo->info->philos[id].fork_mtx);
		return ;
	}
	id = (id + 1) % philo->info->n_philo;
	pthread_mutex_lock(&philo->info->philos[id].fork_mtx);
	print_state(philo, FORK_MSG, FORK_COLOR);
}
