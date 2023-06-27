/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:02:06 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 18:09:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		delay(philo->info->t_die >> 4);
		if (philo->n_eat == philo->info->n_times)
			exit(0);
		else if (died(philo))
		{
			sem_wait(philo->info->print_sem);
			printf(DIE_MSG, ft_getmillis(philo), philo->id + 1);
			exit(1);
		}
	}
}
