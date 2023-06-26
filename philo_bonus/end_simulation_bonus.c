/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:31:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/26 16:44:17 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_simulation(t_simulation *info)
{
	unsigned int	i = 0;
	int				status;
	while (i < info->n_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < info->n_philo)
				kill(info->pids[i++], SIGKILL);
		}
		++i;
	}
	sem_close(info->forks_sem);
	sem_close(info->print_sem);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	free(info->philos);
	free(info->pids);
	// system("leaks -q philo_bonus"); // TODO remove
}
