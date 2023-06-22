/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:02:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/03/08 16:31:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print_mtx);
	if (!simulation_ended(philo) || died(philo))
		printf(msg, ft_getmillis(philo), philo->id + 1);
	pthread_mutex_unlock(&philo->info->print_mtx);
}
