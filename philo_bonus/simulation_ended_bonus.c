/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_ended_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:37:05 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 23:40:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	simulation_ended(t_philo *philo)
{
	if (philo->info->sb_died != INVALID)
		return (TRUE);
	if (philo->n_eat == philo->info->n_times)
		return (TRUE);
	return (died(philo));
}
