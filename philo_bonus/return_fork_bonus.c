/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_fork_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:36:04 by Jkutkut           #+#    #+#             */
/*   Updated: 2023/06/24 21:33:53 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	return_fork(t_philo *philo)
{
	sem_post(philo->info->forks_sem);
	// if (simulation_ended(philo)) // TODO
	// 	return ;
	if (DEBUG)
		print_state(philo, RETURN_FORK_MSG);
}
