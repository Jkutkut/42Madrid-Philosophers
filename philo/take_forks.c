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

#if DEBUG

static void	print_take_fork(t_philo *philo, int fork_id)
{
	printf(TAKE_FORK_MSG, ft_getmillis(philo), philo->id + 1, fork_id);
}

#else

static void	print_take_fork(t_philo *philo, int fork_id)
{
	(void) fork_id;
	printf(TAKE_FORK_MSG, ft_getmillis(philo), philo->id + 1);
}

#endif

static void	take_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->info->philos[fork_id].fork_mtx);
	if (simulation_ended(philo))
		return ;
	pthread_mutex_lock(&philo->info->print_mtx);
	print_take_fork(philo, fork_id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}

static void	double_sword(t_philo *philo)
{
	while (!simulation_ended(philo))
		;
	return (return_fork(philo, philo->id));
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
		return (return_fork(philo, id));
	id = (id + 1) % philo->info->n_philo;
	if (id == philo->id)
		return (double_sword(philo));
	take_fork(philo, id);
	if (simulation_ended(philo))
		return_forks(philo);
}
