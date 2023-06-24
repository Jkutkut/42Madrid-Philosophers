/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_natural_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:48:23 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 12:49:41 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo_result	set_natural(char *str, int *natural)
{
	*natural = ft_atoi(str);
	if (*natural <= 0)
		return (ERROR_NANATURAL_CODE);
	return (SUCCESS);
}
