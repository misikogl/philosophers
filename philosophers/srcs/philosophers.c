/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:55:07 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 17:05:40 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_rule	*rule;

	if (!errorcheck(argc, argv))
	{
		rule = malloc(sizeof(t_rule));
		if (ft_init_rule(rule, argv))
			return (error_manager(1));
		if (ft_init_mutex(rule))
			return (error_manager(2));
		philo_init(rule);
		if (create_threads(rule))
			return (write_error("There was an error creating the threads"));
		return (0);
	}
}
