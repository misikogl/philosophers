/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:01:41 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 06:07:12 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_philo(t_rule *philo, int id, char *string, int color)
{
	pthread_mutex_lock(&(philo->writing));
	if (!(philo->is_dead) && !(philo->temp_eat))
	{
		printf("%lldms ", calculate_time(start_time(), philo->start_time));
		pick_color(color);
		printf("%d ", id + 1);
		printf("%s\n", string);
		reset();
	}
	pthread_mutex_unlock(&(philo->writing));
}

void	check_death_two(t_rule *rule, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < rule->philo_nbr)
	{
		pthread_mutex_lock(&(rule->meal_check));
		if (calculate_time(start_time(), philo[i].last_meal) >= \
			rule->time_to_die)
		{
			pthread_mutex_lock(&(rule->lock));
			print_philo(rule, i, "is dead", 1);
			rule->is_dead = 1;
			pthread_mutex_unlock(&(rule->lock));
			pthread_mutex_unlock(&(rule->meal_check));
			break ;
		}
		pthread_mutex_unlock(&(rule->meal_check));
		usleep (10);
	}
	return ;
}

void	check_death(t_rule *rule, t_philo *philo)
{
	int	i;

	while (!(rule->temp_eat))
	{
		check_death_two(rule, philo);
		pthread_mutex_lock(&(rule->lock));
		if (rule->is_dead)
		{
			pthread_mutex_unlock(&(rule->lock));
			break ;
		}
		pthread_mutex_unlock(&(rule->lock));
		i = 0;
		pthread_mutex_lock(&(rule->lock));
		while (i < rule->philo_nbr && philo[i].max_can_eat >= rule->must_eat && \
				rule->must_eat != -1)
			i++;
		if (rule->philo_nbr == i)
			rule->temp_eat = 1;
		pthread_mutex_unlock(&(rule->lock));
	}
}
