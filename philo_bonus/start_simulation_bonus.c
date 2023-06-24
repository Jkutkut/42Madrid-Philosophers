/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:25:59 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 21:00:46 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	delay(5000);
	printf("Philosopher %d is dead\n", philo->id);
	// TODO
	exit(0);
}

void	child(t_philo *philo)
{
	pthread_create(&philo->thread_id, NULL, monitor, philo);
	philo->l_meal = now();
	while (1)
	{
		philo->info->actions[philo->state](philo);
	}
	// TODO close thread
}

void	start_simulation(t_simulation *inf)
{
	unsigned int	i;

	inf->t0 = now();
	i = 0;
	while (i < inf->n_philo)
	{
		inf->pids[i] = fork();
		if (inf->pids[i] == -1)
			exit(-1); // TODO handle
		if (inf->pids[i] == 0)
			child(&inf->philos[i]);
		++i;
	}
}
