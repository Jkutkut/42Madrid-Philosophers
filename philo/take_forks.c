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

void	double_sword(t_philo *philo)
{
	// take_fork(philo, philo->id);
	while (!simulation_ended(philo))
		;
	return return_fork(philo, philo->id);
}

static void	ft_swap(int *n1, int *n2)
{
	int	tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

static void	get_forks(t_philo *philo, int id1, int id2)
{
	if (id1 == id2)
		return double_sword(philo);
	printf("philo: %d ->    %d -- %d -> swap: %d\n", 
		philo->id + 1,
		philo->id,
		philo->info->n_philo - 1,
		philo->id % 2 == 1 && philo->id != 0
	);
	if (philo->id % 2 == 1 && philo->id != 0)
		ft_swap(&id1, &id2);
	if (simulation_ended(philo))
		return return_fork(philo, id1);
	take_fork(philo, id1);
	if (simulation_ended(philo))
		return return_fork(philo, id1);
	take_fork(philo, id2);
	if (simulation_ended(philo))
		return_forks(philo);
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
	if (id == philo->id)
		return double_sword(philo);
	take_fork(philo, id);
	if (simulation_ended(philo))
		return_forks(philo);

	// get_forks(philo, philo->id, (philo->id + 1) % philo->info->n_philo);
}
