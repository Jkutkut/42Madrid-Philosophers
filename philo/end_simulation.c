/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:10:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/06 12:29:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_simulation *info)
{
	unsigned int	i;

	i = 0;
	while (i < info->n_philo)
		pthread_join(info->philos[i++].thread_id, NULL);
	i = 0;
	while (i < info->n_philo)
		pthread_mutex_destroy(&info->philos[i++].fork_mtx);
	pthread_mutex_destroy(&info->print_mtx);
	free(info->philos);
}
