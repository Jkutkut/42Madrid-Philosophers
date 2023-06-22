/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_natural.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:57:04 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/22 19:00:13 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo_result	set_natural(char *str, int *natural)
{
	*natural = ft_atoi(str);
	if (*natural <= 0)
		return (ERROR_NANATURAL_CODE);
	return (SUCCESS);
}
