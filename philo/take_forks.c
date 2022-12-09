/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:42:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/09 11:25:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int fork_id)
{

	pthread_mutex_lock(&philo->info->philos[fork_id].fork_mtx);
	// TODO check: mutex needed to print?
	pthread_mutex_lock(&philo->info->print_mtx);
	printf(TAKE_FORK_MSG, YELLOW, ft_getmillis(philo), NC, philo->id, fork_id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}


/**
 * @brief Obtain the 2 forks needed to eat.
 * 
 * @param philo Philosopher that is trying to eat.
 */
void	take_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	take_fork(philo, id);
	if (simulation_ended(philo))
		return return_fork(philo, id);
	id = (id + 1) % philo->info->n_philo;
	take_fork(philo, id);
}
