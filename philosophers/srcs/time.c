/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:13:22 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 01:46:18 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	start_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	calculate_time(long long present, long long past)
{
	return (present - past);
}

void	ft_timing(long long time, t_rule *rule)
{
	long long	t;

	t = start_time();
	while (1)
	{
		pthread_mutex_lock(&(rule->lock));
		if (rule->is_dead)
		{
			pthread_mutex_unlock(&(rule->lock));
			break ;
		}
		pthread_mutex_unlock(&(rule->lock));
		if (calculate_time(start_time(), t) >= time)
			break ;
		usleep(150);
	}
}
