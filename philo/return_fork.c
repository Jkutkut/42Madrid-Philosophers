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
/*   Updated: 2022/12/08 18:03:03 by Jkutkut            '-----------------'   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	return_fork(t_simulation *simulation, int philo_id, int fork_id)
{
	pthread_mutex_unlock(&simulation->philos[fork_id].fork_mtx);
	printf("Fhilosopher %d has dropped the fork %d.\n", philo_id, fork_id);
}
