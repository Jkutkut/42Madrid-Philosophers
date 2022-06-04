/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:41:08 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/06/04 19:49:18 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(int error_code)
{
	if (error_code != SUCCESS)
		printf("%sPhilo error%s:\n  ", RED, NC);
	if (error_code == ERROR_ARGS_CODE)
		printf(ERROR_ARGS);
	else if (error_code == ERROR_NAN_CODE)
		printf(ERROR_NANATURAL);
	return (error_code);
}

int	set_natural(char *str, int *natural)
{
	*natural = ft_atoi(str);
	if (*natural <= 0)
		return (ERROR_NAN_CODE);
	return (SUCCESS);
}

int	proccess_args(int argc, char **argv, t_main *info)
{
	int	i;
	int	*arguments;

	info->result_code = ERROR_ARGS_CODE;
	if (argc < 5 || argc > 6)
		return (ERROR_ARGS_CODE);
	info->n_times = -1;
	i = 0;
	arguments = (int *) info;
	while (i++ < argc - 1)
	{
		info->result_code = set_natural(argv[i], &arguments[i - 1]);
		if (info->result_code != SUCCESS)
			break;
	}
	return (info->result_code);
}

int	main(int argc, char **argv)
{
	t_main	info;

	if (proccess_args(argc, argv, &info) != SUCCESS)
		return (error(info.result_code));
	printf("Philo info:\n");
	printf("\tNumber of philosophers: %d\n", info.n_philo);
	printf("\tTime to die: %d\n", info.t_die);
	printf("\tTime to eat: %d\n", info.t_eat);
	printf("\tTime to sleep: %d\n", info.t_sleep);
	printf("\tNumber of times to eat: %d\n", info.n_times);
	
	return (0);
}