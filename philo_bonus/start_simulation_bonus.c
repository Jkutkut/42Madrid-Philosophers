/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:25:59 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 18:10:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_simulation(t_simulation *inf)
{
	unsigned int	i;

	inf->t0 = now();
	i = 0;
	while (i < inf->n_philo)
	{
		inf->pids[i] = fork();
		if (inf->pids[i] == -1)
			exit(1);
		if (inf->pids[i] == 0)
			launch_philo(&inf->philos[i]);
		++i;
	}
}
