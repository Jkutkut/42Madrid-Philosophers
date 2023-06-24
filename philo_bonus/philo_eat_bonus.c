/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:58:32 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 20:59:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *philo)
{
	// TODO take forks
	print_state(philo, EAT_MSG);
	philo->n_eat++;
	philo->l_meal = now();
	delay(philo->info->t_eat);
	// TODO return forks
	philo->state = THINKING;
}
