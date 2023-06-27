/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:02:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 17:15:38 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// TODO doc
static t_philo_result	set_and_return(t_simulation *inf, t_philo_result result)
{
	inf->result_code = result;
	return (result);
}

// TODO doc
static void	base_init(t_simulation *inf)
{
	inf->actions[THINKING] = philo_think;
	inf->actions[EATING] = philo_eat;
	inf->actions[SLEEPING] = philo_sleep;
	inf->sb_died = INVALID;
}

t_philo_result	init_simulation(t_simulation *inf)
{
	unsigned int	i;

	base_init(inf);
	inf->philos = (t_philo *) malloc(sizeof(t_philo) * inf->n_philo);
	inf->pids = (pid_t *) malloc(sizeof(pid_t) * inf->n_philo);
	if (inf->philos == NULL || inf->pids == NULL)
		return (set_and_return(inf, ERROR_MALLOC_CODE));
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_FORKS);
	inf->print_sem = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	inf->forks_sem = sem_open(SEM_FORKS, O_CREAT, 0644, inf->n_philo);
	if (inf->print_sem == SEM_FAILED || inf->forks_sem == SEM_FAILED)
		return (set_and_return(inf, ERROR_SEM_CODE));
	i = 0;
	while (i < inf->n_philo)
	{
		inf->philos[i].id = i;
		inf->philos[i].n_eat = 0;
		inf->philos[i].info = inf;
		inf->philos[i++].state = EATING;
	}
	return (SUCCESS);
}
