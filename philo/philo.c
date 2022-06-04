/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 20:04:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	info;

	if (proccess_args(&info, argc, argv) != SUCCESS)
		return (error(info.result_code));
	printf("Philo info:\n");
	printf("\tNumber of philosophers: %d\n", info.n_philo);
	printf("\tTime to die: %d\n", info.t_die);
	printf("\tTime to eat: %d\n", info.t_eat);
	printf("\tTime to sleep: %d\n", info.t_sleep);
	printf("\tNumber of times to eat: %d\n", info.n_times);
	
	return (0);
}