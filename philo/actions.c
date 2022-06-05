/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 19:30:32 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	pthread_mutex_lock(&philo->info->philos[id].fork_mtx);
	print_state(philo, FORK_MSG, FORK_COLOR);
	id = (id + 1) % philo->info->n_philo;
	pthread_mutex_lock(&philo->info->philos[id].fork_mtx);
	print_state(philo, FORK_MSG, FORK_COLOR);
}

static void	drop_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	pthread_mutex_unlock(&philo->info->philos[id].fork_mtx);
	id = (id + 1) % philo->info->n_philo;
	pthread_mutex_unlock(&philo->info->philos[id].fork_mtx);
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	print_state(philo, EAT_MSG, EAT_COLOR);
	delay(philo->info->t_eat);
	philo->n_eat++;
	philo->l_meal = now();
	drop_forks(philo);
	philo->state = THINKING;
}
