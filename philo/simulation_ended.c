/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_ended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:08:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 22:50:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Analyzes the simulation and determines if the simulation should end
 * for the given philosopher.
 * 
 * @param philo Philosopher to analyze.
 * @return int TRUE if the simulation should end, FALSE otherwise.
 */
int	simulation_ended(t_philo *philo)
{
	if (philo->info->sb_died)
		return (TRUE);
	if (philo->n_eat == philo->info->n_times)
		return (TRUE);
	if (now() - philo->l_meal >= philo->info->t_die)
	{
		philo->info->sb_died = TRUE;
		print_state(philo, DIE_MSG, DIE_COLOR);
		drop_all_forks(philo->info);
		return (TRUE);
	}
	return (FALSE);
}
