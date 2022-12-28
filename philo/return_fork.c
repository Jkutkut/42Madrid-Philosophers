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
/*   Updated: 2022/12/28 14:30:10 by Jkutkut            '-----------------'   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	return_fork(t_philo *philo, int fork_id)
{
	
	pthread_mutex_unlock(&philo->info->philos[fork_id].fork_mtx);
	if (died(philo))
		return ;
	pthread_mutex_lock(&philo->info->print_mtx);
	if (DEBUG)
		printf(RETURN_FORK_MSG, YELLOW, ft_getmillis(philo), NC, philo->id, fork_id);
	pthread_mutex_unlock(&philo->info->print_mtx);
}
