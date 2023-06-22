/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:46:10 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/22 18:57:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	return_forks(t_philo *philo)
{
	int	id;

	id = philo->id;
	return_fork(philo, id);
	id = (id + 1) % philo->info->n_philo;
	return_fork(philo, id);
}
