/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:48:55 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 12:49:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stddef.h>
#include <limits.h>

#define SPACES " \n\v\f\r\t"
#define NUMBERS "0123456789"

static int	ft_hasany(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

unsigned int	ft_atoi(char *str)
{
	size_t	number;
	size_t	i;

	i = 0;
	number = 0;
	while (ft_hasany(SPACES, str[i]))
		i++;
	while (ft_hasany(NUMBERS, str[i]))
	{
		number *= 10;
		number += (str[i++] - 48);
	}
	while (ft_hasany(SPACES, str[i]))
		i++;
	if (number > LONG_MAX || str[i])
		return (-1);
	return (number);
}
