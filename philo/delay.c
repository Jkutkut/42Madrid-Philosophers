/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:51:07 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/19 18:59:31 by jre-gonz         ###   ########.fr       */
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
void	delay(long ms)
{
	usleep(ms * 1000);
}
