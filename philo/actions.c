/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 18:01:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	print_state(philo, FORK_MSG);
	print_state(philo, EAT_MSG);
	// TODO: eat
	// philo->n_eat++;
	delay(philo->info->t_eat);
	philo->state = THINKING;
}

void	philo_think(t_philo *philo)
{
	print_state(philo, THINK_MSG);
	philo->state = SLEEPING;
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, SLEEP_MSG);
	delay(philo->info->t_sleep);
	philo->state = EATING;
}