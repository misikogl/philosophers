/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 01:42:33 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 01:59:45 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_eat_philos(t_philo *philo)
{
	t_rule	*rules;

	rules = philo->rule;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	print_philo(rules, philo->id, "has taken a fork", 2);
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	print_philo(rules, philo->id, "has taken a fork", 2);
	print_philo(rules, philo->id, "is eating", 3);
	ft_timing(rules->time_to_eat, rules);
	pthread_mutex_lock(&(rules->meal_check));
	philo->last_meal = start_time();
	pthread_mutex_unlock(&(rules->meal_check));
	pthread_mutex_lock(&(rules->lock));
	philo->max_can_eat++;
	pthread_mutex_unlock(&(rules->lock));
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	*ft_dinner(void *philos)
{
	t_philo	*philo;
	t_rule	*rules;

	philo = (t_philo *)philos;
	rules = philo->rule;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->is_dead))
	{
		pthread_mutex_lock(&(rules->lock));
		if (rules->temp_eat)
		{
			pthread_mutex_unlock(&(rules->lock));
			break ;
		}
		pthread_mutex_unlock(&(rules->lock));
		ft_eat_philos(philo);
		print_philo(rules, philo->id, "is sleeping", 4);
		ft_timing(rules->time_to_sleep, rules);
		print_philo(rules, philo->id, "is thinking", 5);
	}
	return (NULL);
}
