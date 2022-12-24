/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:07:30 by misikogl          #+#    #+#             */
/*   Updated: 2022/12/21 01:57:46 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	writerror(int exit_mode)
{
	if (exit_mode == 1)
	{
		red();
		printf("THE NUMBER OF ARGUMANS IS WRONG\n");
	}
	if (exit_mode == 2)
	{
		red ();
		printf("INPUTS BE ONLY NUMBERS\n");
	}
	if (exit_mode == 3)
	{
		red ();
		printf("THERE HAS TO BE AT LEAST ONE PHILOSOPHER\n");
	}
	if (exit_mode == 4)
	{
		red ();
		printf("TIMES EVERY PHILOSOPHERS EATS HAS TO BE GREATER THAN 0\n");
	}
}

int	errorcheck(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		writerror(1);
		return (1);
	}
	if (is_al_num(argv[1]) || is_al_num(argv[2]) || \
			is_al_num(argv[3]) || is_al_num(argv[4]))
	{
		writerror(2);
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		writerror(3);
		return (1);
	}
	if (errorcheck_two(argc, argv))
		return (1);
	return (0);
}

int	errorcheck_two(int argc, char **argv)
{
	if (argv[5])
	{
		if (is_al_num(argv[5]))
		{
			writerror(2);
			return (1);
		}
		if (ft_atoi(argv[5]) < 1)
		{
			writerror(4);
			return (1);
		}
	}
	return (0);
}

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("Fatal error: At least one wrong argument"));
	if (error == 2)
		return (write_error("Fatal error: when intializing mutex"));
	return (1);
}
