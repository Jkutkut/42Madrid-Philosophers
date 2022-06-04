/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:59:33 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 18:04:40 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include <unistd.h>

#include <stdio.h>
#include <string.h>


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
	// if (ms > 1000)
	// 	usleep((ms >> 1) * 1000);
	while (get_ms() - now < ms)
		;
}

#define TIME 12000

int	main(int argc, char **argv)
{
	long	start;
	long	end;

	if (argc != 2)
	{
		printf("Usage: ./measure_time [original|optimized]\n");
		return (0);
	}
	if (strcmp(argv[1], "original") == 0)
	{
		start = get_ms();
		usleep(TIME * 1000);
		end = get_ms();
	}
	else if (strcmp(argv[1], "optimized") == 0)
	{
		start = get_ms();
		mimir(TIME);
		end = get_ms();
	}
	else
	{
		printf("Usage: ./measure_time [original|optimized]\n");
		return (0);
	}
	printf("%ld\n", end - start);
	return (0);
}