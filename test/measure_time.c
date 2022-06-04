/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 17:47:08 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include <unistd.h>

#include <stdio.h>


long	get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	mimir(long ms)
{
	long	now;

	now = get_ms();
	if (ms > 1000)
		usleep((ms >> 1) * 1000);
	while (get_ms() - now < ms)
		;
}

#define TIME 12000

int	main(int argc, char **argv)
{
	long	start;
	long	end;

	if (argc == 1)
	{
		start = get_ms();
		mimir(TIME);
		end = get_ms();
	}
	else
	{
		start = get_ms();
		usleep(TIME * 1000);
		end = get_ms();
	}
	printf("%ld\n", end - start);
	return (0);
}