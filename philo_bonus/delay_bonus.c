/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:48:09 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/06/24 20:48:16 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	delay(long ms)
{
	long	end;
	long	steps;

	end = now() + ms;
	steps = 2 * ms;
	usleep(ms * 940);
	while (now() < end)
		usleep(steps);
}
