/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:10:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 20:31:12 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Joins all the threads and frees all the allocated memory.
 * 
 * @param info Structure with all the information about the philosophers.
 */
void	end_simulation(t_simulation *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
		pthread_join(info->philos[i].thread_id, NULL);
	i = -1;
	while (++i < info->n_philo)
		pthread_mutex_destroy(&info->philos[i].fork_mtx);
	pthread_mutex_destroy(&info->print_mtx);
	free(info->philos);
}
