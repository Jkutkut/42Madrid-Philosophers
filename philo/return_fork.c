/* ************************************************************************** */
/*                                                                            */
/*                                                        .-------------.     */
/*                                                        |.-----------.|     */
/*                                                        ||           ||     */
/*                                                        ||  Jkutkut  ||     */
/*   return_fork.c                                        ||           ||     */
/*                                                        |'-----------'|     */
/*   By: Jkutkut  https://github.com/jkutkut              /:::::::::::::\     */
/*                                                       /:::::::::::::::\    */
/*   Created: 2022/12/08 17:36:04 by Jkutkut            /:::===========:::\   */
/*   Updated: 2022/12/09 11:22:57 by Jkutkut            '-----------------'   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	return_fork(t_philo *philo, int fork_id)
{
	
	pthread_mutex_unlock(&philo->info->philos[fork_id].fork_mtx);
	// TODO check: mutex needed to print?
	pthread_mutex_lock(&philo->info->print_mtx);
	printf(RETURN_FORK_MSG, YELLOW, ft_getmillis(philo), NC, philo->id, fork_id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}
