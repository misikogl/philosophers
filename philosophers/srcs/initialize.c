/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:59:15 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 01:52:29 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_init_rule(t_rule *rule, char **argv)
{
	rule->philo_nbr = ft_atoi(argv[1]);
	rule->time_to_die = ft_atoi(argv[2]);
	rule->time_to_eat = ft_atoi(argv[3]);
	rule->time_to_sleep = ft_atoi(argv[4]);
	rule->temp_eat = 0;
	if (rule->philo_nbr < 1 || rule->time_to_die < 60 || rule->time_to_eat < 60 \
			|| rule->time_to_sleep < 60 || rule->philo_nbr > 200)
		return (1);
	if (argv[5])
		rule->must_eat = ft_atoi(argv[5]);
	else
		rule->must_eat = -1;
	return (0);
}

int	ft_init_mutex(t_rule *rule)
{
	int	i;

	i = rule->philo_nbr;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rule->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rule->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rule->meal_check), NULL))
		return (1);
	if (pthread_mutex_init(&(rule->lock), NULL))
		return (1);
	return (0);
}

void	philo_init(t_rule *rule)
{
	int	i;

	i = rule->philo_nbr;
	while (--i >= 0)
	{
		rule->philo[i].id = i;
		rule->philo[i].left_fork_id = i;
		rule->philo[i].right_fork_id = (i + 1) % rule->philo_nbr;
		rule->philo[i].rule = rule;
		rule->philo[i].last_meal = 0;
		rule->philo[i].max_can_eat = 0;
	}
}

void	pick_color(int color)
{
	if (color == 1)
		red ();
	if (color == 2)
		green ();
	if (color == 3)
		blue ();
	if (color == 4)
		yellow ();
	if (color == 5)
		purple ();
}
