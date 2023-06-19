/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:42:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/03/08 16:32:34 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int fork_id)
{

	pthread_mutex_lock(&philo->info->philos[fork_id].fork_mtx);
	if (simulation_ended(philo))
		return ;
	pthread_mutex_lock(&philo->info->print_mtx);
	if (DEBUG)
		printf(TAKE_FORK_MSG, YELLOW, ft_getmillis(philo), NC, philo->id + 1, fork_id);
	else
		printf(TAKE_FORK_MSG_CLASSIC, ft_getmillis(philo), philo->id + 1);
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
	if (simulation_ended(philo))
		return return_forks(philo);
}
