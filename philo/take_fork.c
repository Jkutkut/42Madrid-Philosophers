/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:05:29 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/22 19:10:34 by jre-gonz         ###   ########.fr       */
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

void	take_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_lock(&philo->info->philos[fork_id].fork_mtx);
	if (simulation_ended(philo))
		return ;
	pthread_mutex_lock(&philo->info->print_mtx);
	print_take_fork(philo, fork_id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}
