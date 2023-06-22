/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:53:34 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/06 10:30:38 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

#define SPACES " \n\v\f\r\t"
#define NUMBERS "0123456789"

// TODO update with new version from libft
static int	ft_hasany(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}

/**
 * @brief Converts a string to an integer.
 * 
 * @param str String to convert.
 * @return int Number representing the string.
 */
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
