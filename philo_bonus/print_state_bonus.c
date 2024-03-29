/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:02:06 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 23:57:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_state(t_philo *philo, char *msg)
{
	sem_wait(philo->info->print_sem);
	if (!simulation_ended(philo))
		printf(msg, ft_getmillis(philo), philo->id + 1);
	sem_post(philo->info->print_sem);
}
