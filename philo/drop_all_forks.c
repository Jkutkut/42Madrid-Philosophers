/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_all_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:48:46 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/06 10:27:47 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_all_forks(t_simulation *info)
{
	unsigned int	i;

	i = 0;
	while (i < info->n_philo)
		pthread_mutex_unlock(&info->philos[i++].fork_mtx);
}
