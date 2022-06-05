/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:24:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 18:58:48 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	print_state(philo, FORK_MSG, FORK_COLOR);
	print_state(philo, FORK_MSG, FORK_COLOR);
	print_state(philo, EAT_MSG, EAT_COLOR);
	// TODO: eat
	// philo->n_eat++;
	delay(philo->info->t_eat);
	philo->state = THINKING;
}
