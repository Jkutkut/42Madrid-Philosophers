/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:01:21 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/19 18:56:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Updates the main struct with the arguments given.
 * 
 * The code updates the first 5 variables on the struct as they're ints.
 * 
 * @param info The main struct to update.
 * @param argc argc from main.
 * @param argv argv from main.
 * @return int SUCCESS if everything went well, ERROR code otherwise.
 */
t_philo_result	proccess_args(t_simulation *info, int argc, char **argv)
{
	int	i;
	int	*arguments;

	if (argc < 5 || argc > 6)
		return (ERROR_ARGS_CODE);
	info->n_times = PHEUDO_INFINITE;
	arguments = (int *) info;
	i = 0;
	info->result_code = SUCCESS;
	while (i++ < argc - 1 && info->result_code == SUCCESS)
		info->result_code = set_natural(argv[i], &arguments[i - 1]);
	return (info->result_code);
}
