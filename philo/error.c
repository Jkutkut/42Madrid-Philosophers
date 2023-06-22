/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:54:54 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 23:41:20 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_result	error(t_philo_result error_code)
{
	if (error_code != SUCCESS)
		printf(ERROR);
	if (error_code == ERROR_ARGS_CODE)
		printf(ERROR_ARGS);
	else if (error_code == ERROR_NANATURAL_CODE)
		printf(ERROR_NANATURAL);
	else if (error_code == ERROR_MALLOC_CODE)
		printf(ERROR_MALLOC);
	// TODO thread errors?
	return (error_code);
}
