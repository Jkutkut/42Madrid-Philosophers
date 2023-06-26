/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:42:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/26 16:26:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_simulation	info;

	if (proccess_args(&info, argc, argv) != SUCCESS)
		return (error(info.result_code));
	if (DEBUG)
	{
		printf("Philo info:\n");
		printf("  Number of philosophers: %d\n", info.n_philo);
		printf("  Time to die: %d\n", info.t_die);
		printf("  Time to eat: %d\n", info.t_eat);
		printf("  Time to sleep: %d\n", info.t_sleep);
		printf("  Number of times to eat: %d\n", info.n_times);
	}
	if (init_simulation(&info) != SUCCESS)
		return (error(info.result_code));
	start_simulation(&info);
	// end_simulation(&info);
	unsigned int	i = 0;
	int				status;
	while (i < info.n_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < info.n_philo)
				kill(info.pids[i++], SIGKILL);
		}
		++i;
	}
	return (0);
}
