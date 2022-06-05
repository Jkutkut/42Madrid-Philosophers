/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 16:50:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->print_mtx);
	printf(msg, 0, philo->id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}

int	simulation_ended(t_philo *philo)
{
	if (philo->info->sb_died)
		return (TRUE);
	if (philo->n_eat == philo->info->n_times)
		return (TRUE);
	// If philo should die because of starvation
		// anounce dead
		// update info to end the rest of the simulation
		// return TRUE
	return (FALSE);
}

void	*live(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	printf("Philosopher %d is alive\n", philo->id);
	while (1)
	{
		if (simulation_ended(philo))
			break;
		philo->info->actions[philo->state](philo);
	}
	printf("Philosopher %d's simulation ended\n", philo->id);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_simulation	info;

	if (proccess_args(&info, argc, argv) != SUCCESS)
		return (error(info.result_code));
	printf("Philo info:\n");
	printf("\tNumber of philosophers: %d\n", info.n_philo);
	printf("\tTime to die: %d\n", info.t_die);
	printf("\tTime to eat: %d\n", info.t_eat);
	printf("\tTime to sleep: %d\n", info.t_sleep);
	printf("\tNumber of times to eat: %d\n", info.n_times);
	if (init_simulation(&info) != SUCCESS)
		return (error(info.result_code));
	end_simulation(&info);
	return (0);
}