/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:31:51 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 02:01:24 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	create_threads(t_rule *rule)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(rule->lock));
	rule->start_time = start_time();
	pthread_mutex_unlock(&(rule->lock));
	while (i < rule->philo_nbr)
	{
		if (pthread_create(&(rule->philo[i].thread), NULL, ft_dinner, \
					&(rule->philo[i])))
			return (1);
		pthread_mutex_lock(&(rule->lock));
		rule->philo[i].last_meal = start_time();
		pthread_mutex_unlock(&(rule->lock));
		i++;
	}
	check_death(rule, rule->philo);
	exit_thread(rule, rule->philo);
	return (0);
}
