/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_ended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:08:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/28 22:17:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Analyzes the simulation and determines if the simulation should end
 * for the given philosopher.
 * 
 * @param philo Philosopher to analyze.
 * @return TRUE if the simulation should end, FALSE otherwise.
 */
t_bool	simulation_ended(t_philo *philo)
{
	if (philo->info->sb_died != INVALID)
		return (TRUE);
	if (philo->n_eat == philo->info->n_times)
		return (TRUE);
	if (died(philo))
	{
		philo->info->sb_died = philo->id;
		return (TRUE);
	}
	return (FALSE);
}
