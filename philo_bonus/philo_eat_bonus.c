/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:58:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 21:28:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *philo)
{
	take_fork(philo); // TODO check
	take_fork(philo);
	print_state(philo, EAT_MSG);
	philo->n_eat++;
	philo->l_meal = now();
	delay(philo->info->t_eat);
	return_fork(philo); // TODO check
	return_fork(philo);
	philo->state = THINKING;
}
