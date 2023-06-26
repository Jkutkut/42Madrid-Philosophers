/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:36:04 by Jkutkut           #+#    #+#             */
/*   Updated: 2023/06/26 16:18:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	return_fork(t_philo *philo, int fork_id)
{
	pthread_mutex_unlock(&philo->info->philos[fork_id].fork_mtx);
	if (simulation_ended(philo))
		return ;
	pthread_mutex_lock(&philo->info->print_mtx);
	if (DEBUG && !simulation_ended(philo))
		printf(RETURN_FORK_MSG, ft_getmillis(philo), philo->id, fork_id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}
