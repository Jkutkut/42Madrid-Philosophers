/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:02:48 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 17:13:03 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#define SEM_FORKS "/forks"
#define SEM_PRINT "/print"

void	base_init(t_simulation *inf)
{
	// TODO
	// inf->actions[THINKING] = philo_think;
	// inf->actions[EATING] = philo_eat;
	// inf->actions[SLEEPING] = philo_sleep;
	inf->sb_died = INVALID;
}

t_philo_result	init_simulation(t_simulation *inf)
{
	unsigned int	i;

	base_init(inf);
	inf->philos = (t_philo *) malloc(sizeof(t_philo) * inf->n_philo);
	if (inf->philos == NULL)
	{
		inf->result_code = ERROR_MALLOC_CODE;
		return (inf->result_code);
	}
	sem_unlink(SEM_PRINT); // TODO error handling
	sem_unlink(SEM_FORKS); // TODO error handling
	inf->print_sem = sem_open(SEM_PRINT, O_CREAT, 0644, 1); // TODO error handling
	inf->forks_sem = sem_open(SEM_FORKS, O_CREAT, 0644, inf->n_philo); // TODO error handling
	inf->t0 = now();
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