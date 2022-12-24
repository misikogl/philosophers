/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:54:15 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/22 20:12:53 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	exit_thread(t_rule *rule, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rule->philo_nbr)
	{
		if (rule->philo_nbr == 1)
			break ;
		pthread_join(philo[i].thread, NULL);
	}
	i = -1;
	while (++i < rule->philo_nbr)
		pthread_mutex_destroy(&(rule->forks[i]));
	pthread_mutex_destroy(&(rule->writing));
	pthread_mutex_destroy(&(rule->lock));
}
