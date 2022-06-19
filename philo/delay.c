/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:51:07 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/19 19:08:52 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
void	delay(long ms)
{
	// long	now;

	// now = get_ms();
	// if (ms > 1000)
	// 	usleep((ms >> 1) * 1000);
	// while (get_ms() - now < ms)
	// 	;
}*/
/**
 * @brief Custom function that waits the given amount of milliseconds.
 * 
 * @param ms Amount of milliseconds to wait.
 */
void	delay(long ms)
{
	usleep(ms * 1000);
}
