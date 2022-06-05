/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_all_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:48:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 19:56:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Forces all philosophers to drop their forks.
 * 
 * @param info Struct storing the philosophers and the simulation info.
 */
void	drop_all_forks(t_simulation *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
		pthread_mutex_unlock(&info->philos[i].fork_mtx);
}