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

/**
 * @brief Prints the error message defined by the error code.
 * 
 * If success code is given, nothing is printed.
 * 
 * @param error_code Error code.
 * @return int The input given.
 */
int	error(int error_code)
{
	if (error_code != SUCCESS)
		printf("%sPhilo error%s:\n  ", RED, NC);
	if (error_code == ERROR_ARGS_CODE)
		printf(ERROR_ARGS);
	else if (error_code == ERROR_NANATURAL_CODE)
		printf(ERROR_NANATURAL);
	else if (error_code == ERROR_MALLOC_CODE)
		printf(ERROR_MALLOC);
	return (error_code);
}