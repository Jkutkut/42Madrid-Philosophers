/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 18:44:26 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_natural(char *str, int *natural)
{
	*natural = ft_atoi(str);
	if (*natural < 0)
		return (ERROR_NAN_CODE);
	return (SUCCESS);
}

int	proccess_args(int argc, char **argv, t_philo *philo)
{
	if (argc < 4 || argc > 5)
		return (ERROR_ARGS_CODE);
	
	
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (!proccess_args(argc, argv, &philo))
	{
		ft_putstr(ERROR_ARGS);
		return (0);
	}
	return (0);
}