/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_ended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:08:37 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/22 19:00:51 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
