/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:42:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/22 19:07:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	take_fork(philo, id);
	if (simulation_ended(philo))
		return (return_fork(philo, id));
	id = (id + 1) % philo->info->n_philo;
	if (id == philo->id)
	{
		while (!simulation_ended(philo))
			;
		return (return_fork(philo, philo->id));
	}
	take_fork(philo, id);
	if (simulation_ended(philo))
		return_forks(philo);
}
