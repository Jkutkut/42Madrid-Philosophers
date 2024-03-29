/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:42:36 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 17:19:50 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_simulation	info;

	if (proccess_args(&info, argc, argv) != SUCCESS)
		return (error(info.result_code));
	print_simulation(info);
	if (init_simulation(&info) != SUCCESS)
		return (error(info.result_code));
	start_simulation(&info);
	end_simulation(&info);
	return (0);
}
