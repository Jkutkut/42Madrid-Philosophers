/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:13:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 20:09:49 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Creates all the necessary threads and logic to make the simulation.
 * 
 * @param info Structure with all the information about the philosophers.
 * @return int SUCCESS if everything went well, ERROR code if there was any.
 */
int	init_simulation(t_simulation *info)
{
	int	i;

	info->actions[THINKING] = philo_think;
	info->actions[EATING] = philo_eat;
	info->actions[SLEEPING] = philo_sleep;
	pthread_mutex_init(&info->print_mtx, NULL);
	info->sb_died = FALSE;
	info->philos = (t_philo *) malloc(sizeof(t_philo) * info->n_philo);
	if (info->philos == NULL)
	{
		info->result_code = ERROR_MALLOC_CODE;
		return (info->result_code);
	}
	info->t0 = now();
	i = -1;
	while (++i < info->n_philo)
	{
		info->philos[i].id = i;
		info->philos[i].n_eat = 0;
		info->philos[i].info = info;
		pthread_mutex_init(&info->philos[i].fork_mtx, NULL);
		info->philos[i].state = EATING;
		pthread_create(&info->philos[i].thread_id, NULL, &live, &info->philos[i]);
	}
	return (SUCCESS);
}