/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:02:06 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 21:02:44 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_state(t_philo *philo, char *msg)
{
	// TODO lock sem
	// if (!simulation_ended(philo) || died(philo)) // TODO
		printf(msg, ft_getmillis(philo), philo->id + 1);
	// TODO unlock sem
}
