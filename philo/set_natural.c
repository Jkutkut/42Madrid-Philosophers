/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_natural.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:57:04 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 19:58:23 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Updates the given int value with the given string using ft_atoi.
 * 
 * @param str String to convert.
 * @param natural Pointer to the int to update.
 * @return int SUCCESS if successful, else ERROR_NANATURAL_CODE.
 */
t_philo_result	set_natural(char *str, int *natural)
{
	*natural = ft_atoi(str);
	if (*natural <= 0)
		return (ERROR_NANATURAL_CODE);
	return (SUCCESS);
}
