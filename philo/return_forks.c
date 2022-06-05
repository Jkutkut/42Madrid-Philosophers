/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:46:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 22:46:43 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Return to the table the 2 forks used to eat.
 * 
 * @param philo Philosopher that just finished eating.
 */
void	return_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	pthread_mutex_unlock(&philo->info->philos[id].fork_mtx);
	id = (id + 1) % philo->info->n_philo;
	pthread_mutex_unlock(&philo->info->philos[id].fork_mtx);
}