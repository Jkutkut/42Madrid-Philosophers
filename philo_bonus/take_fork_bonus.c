/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:20:22 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 21:33:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->info->forks_sem);
	// if (simulation_ended(philo)) // TODO
	// 	return ;
	print_state(philo, TAKE_FORK_MSG);
}
