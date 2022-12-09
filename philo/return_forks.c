/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:46:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/09 11:23:31 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Return to the table the 2 forks used to eat.
 * 
 * @param philo Philosopher that just finished eating.
 */
void	return_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	return_fork(philo, id);
	id = (id + 1) % philo->info->n_philo;
	return_fork(philo, id);
}
