/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:31:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 17:57:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Get the status code of the given process code.
 * 
 * @param process_code Process code to get the status code from.
 * @return int Status code of the given process code.
 */
static int	get_exit_value(int process_code)
{
	int	status_code;

	status_code = WEXITSTATUS(process_code);
	if (WIFEXITED(process_code))
		status_code = WEXITSTATUS(process_code);
	else if (WIFSIGNALED(process_code))
		status_code = WTERMSIG(process_code) + 128;
	return (status_code);
}

void	end_simulation(t_simulation *info)
{
	unsigned int	i;
	int				status;

	i = 0;
	while (i < info->n_philo)
	{
		waitpid(-1, &status, 0);
		if (get_exit_value(status) != 0)
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
}
