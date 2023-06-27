/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_fork_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:36:04 by Jkutkut           #+#    #+#             */
/*   Updated: 2023/06/27 17:05:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	return_fork(t_philo *philo)
{
	sem_post(philo->info->forks_sem);
	if (DEBUG && !simulation_ended(philo))
		print_state(philo, RETURN_FORK_MSG);
}
