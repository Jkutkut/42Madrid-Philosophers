/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 22:47:15 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	if (simulation_ended(philo))
		return ;
	print_state(philo, EAT_MSG, EAT_COLOR);
	delay(philo->info->t_eat);
	philo->n_eat++;
	philo->l_meal = now();
	return_forks(philo);
	philo->state = THINKING;
}
