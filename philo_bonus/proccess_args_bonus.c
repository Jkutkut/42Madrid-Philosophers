/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:43:39 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 13:32:37 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo_result	proccess_args(t_simulation *info, int argc, char **argv)
{
	int	i;
	int	*arguments;

	info->result_code = ERROR_ARGS_CODE;
	if (argc < 5 || argc > 6)
		return (info->result_code);
	info->n_times = PHEUDO_INFINITE;
	arguments = (int *) info;
	i = 0;
	info->result_code = SUCCESS;
	while (i++ < argc - 1 && info->result_code == SUCCESS)
		info->result_code = set_natural(argv[i], &arguments[i - 1]);
	return (info->result_code);
}
