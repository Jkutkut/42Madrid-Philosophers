/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:19:47 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/06 11:52:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_simulation *inf)
{
	unsigned int	i;

	i = 0;
	while (i < inf->n_philo)
	{
		pthread_create(&inf->philos[i].thread_id, NULL, &live, &inf->philos[i]);
		++i;
	}
}
