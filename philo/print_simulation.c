/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:19:40 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 17:31:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#if DEBUG

void	print_simulation(t_simulation info)
{
	printf(PSTATE_TITLE);
	printf(PSTATE_NBR_PHI, info.n_philo);
	printf(PSTATE_T2D, info.t_die);
	printf(PSTATE_T2E, info.t_eat);
	printf(PSTATE_T2S, info.t_sleep);
	printf(PSTATE_NBR_T2E, info.n_times);
}

#else

void	print_simulation(t_simulation info)
{
	(void) info;
}

#endif
