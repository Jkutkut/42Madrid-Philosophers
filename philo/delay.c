/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:51:07 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/12/27 15:45:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Custom function that waits the given amount of milliseconds.
 * The use of usleep is now good enough.
 *
 * @param ms Amount of milliseconds to wait.
 */
void	delay(long ms)
{
	long	t;

	t = now();
	//if (ms > 1000)
	//	usleep((ms >> 1) * 1000);
	//while (now() - t < ms)
	//	;
	usleep(ms * 920);
	while(now() < t + ms)
		usleep(ms * 3);
}
