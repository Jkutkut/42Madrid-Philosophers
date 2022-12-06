/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/06 10:35:39 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_simulation	info;

	if (proccess_args(&info, argc, argv) != SUCCESS)
		return (error(info.result_code));
	printf("Philo info:\n"); // TODO refactor strings into .h
	printf("  Number of philosophers: %d\n", info.n_philo);
	printf("  Time to die: %d\n", info.t_die);
	printf("  Time to eat: %d\n", info.t_eat);
	printf("  Time to sleep: %d\n", info.t_sleep);
	printf("  Number of times to eat: %d\n", info.n_times);
	if (init_simulation(&info) != SUCCESS)
		return (error(info.result_code));
	end_simulation(&info);
	return (0);
}
