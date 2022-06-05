/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/05 13:13:12 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_main(t_main *info)
{
	int	i;

	pthread_mutex_init(&info->print_mtx, NULL);
	info->sb_died = FALSE;
	info->philos = (t_philo *) malloc(sizeof(t_philo) * info->n_philo);
	if (info->philos == NULL)
		info->result_code = ERROR_MALLOC_CODE;
	i = -1;
	while (++i < info->n_philo)
	{
		info->philos[i].id = i;
		info->philos[i].n_eat = 0;
		info->philos[i].info = info;
		pthread_mutex_init(&info->philos[i].fork_mtx, NULL);
		info->philos[i].state = EATING;
		info->philos[i].l_meal = now();
		// pthread_create(&info->thread_id, NULL, TODO, &info->philos[i]);
	}
	return (info->result_code);
}

int	main(int argc, char **argv)
{
	t_main	info;

	if (proccess_args(&info, argc, argv) != SUCCESS)
		return (error(info.result_code));
	if (init_main(&info) != SUCCESS)
		return (error(info.result_code));
	printf("Philo info:\n");
	printf("\tNumber of philosophers: %d\n", info.n_philo);
	printf("\tTime to die: %d\n", info.t_die);
	printf("\tTime to eat: %d\n", info.t_eat);
	printf("\tTime to sleep: %d\n", info.t_sleep);
	printf("\tNumber of times to eat: %d\n", info.n_times);
	
	return (0);
}