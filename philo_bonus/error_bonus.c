/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:10:20 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/27 18:20:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	else if (error_code == ERROR_SEM_CODE)
		printf(ERROR_SEM);
	return (error_code);
}
