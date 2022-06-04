/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 16:58:29 by jre-gonz         ###   ########.fr       */
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

	if (ms > 1000)
	{
		usleep((long) (0.9 * ms * 1000));
		ms = ms / 10;
	}
	now = get_ms();
	while (get_ms() - now < ms)
		;
}

int	main(int argc, char **argv)
{
	long	start;
	long	end;

	if (argc == 1)
	{
		start = get_ms();
		mimir(1200);
		end = get_ms();
	}
	else
	{
		start = get_ms();
		usleep(1200 * 1000);
		end = get_ms();
	}
	printf("%ld\n", end - start);
	return (0);
}