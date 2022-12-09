/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:13:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/09 11:29:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Creates all the necessary threads and logic to make the simulation.
 * 
 * @param inf Structure with all the information about the philosophers.
 * @return int SUCCESS if everything went well, ERROR code if there was any.
 */
int	init_simulation(t_simulation *inf)
{
	int	i;

	inf->actions[THINKING] = philo_think;
	inf->actions[EATING] = philo_eat;
	inf->actions[SLEEPING] = philo_sleep;
	pthread_mutex_init(&inf->print_mtx, NULL);
	inf->sb_died = FALSE;
	inf->philos = (t_philo *) malloc(sizeof(t_philo) * inf->n_philo);
	if (inf->philos == NULL)
	{
		inf->result_code = ERROR_MALLOC_CODE;
		return (inf->result_code);
	}
	inf->t0 = now();
	i = -1;
	while (++i < inf->n_philo)
	{
		inf->philos[i].id = i;
		inf->philos[i].n_eat = 0;
		inf->philos[i].info = inf;
		pthread_mutex_init(&inf->philos[i].fork_mtx, NULL);
		inf->philos[i].state = EATING;
	}
	return (SUCCESS);
}
