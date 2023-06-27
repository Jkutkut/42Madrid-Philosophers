/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:03:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 18:07:12 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	launch_philo(t_philo *philo)
{
	pthread_create(&philo->thread_id, NULL, monitor, philo);
	philo->l_meal = now();
	if (philo->id % 2 == 0)
		delay(philo->info->t_sleep >> 2);
	while (1)
		philo->info->actions[philo->state](philo);
}
