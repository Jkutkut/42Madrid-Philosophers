/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:25:59 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 17:05:27 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		delay(philo->info->t_die >> 8); // TODO analyze
		if (philo->info->sb_died != INVALID)
			exit(0);
		else if (philo->n_eat == philo->info->n_times)
			exit(0);
		else if (died(philo))
		{
			philo->info->sb_died = philo->id;
			sem_wait(philo->info->print_sem);
			printf(DIE_MSG, ft_getmillis(philo), philo->id + 1);
			// sem_post(philo->info->print_sem); // ! TODO remove
			exit(1);
		}
	}
}

void	child(t_philo *philo)
{
	pthread_create(&philo->thread_id, NULL, monitor, philo); // TODO handle
	philo->l_meal = now();
	if (philo->id % 2 == 0)
		delay(philo->info->t_sleep >> 2);
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
