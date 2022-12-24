/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:50:54 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 02:02:03 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	red(void)
{
	printf("\033[1;31m");
}

void	yellow(void)
{
	printf("\033[0;33m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	blue(void)
{
	printf("\033[0;34m");
}

void	purple(void)
{
	printf("\033[0;35m");
}
