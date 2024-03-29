/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:51:07 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/03/08 16:35:24 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
