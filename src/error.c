/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:58:36 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/18 18:17:24 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(char *str)
{
	ft_free();
	printf(RED "%s" RESET, str);
	exit(0);
}

void	ft_check_signe(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 1;
	flag = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] != ' ' && flag == 0)
			{
				flag = 1;
				if (argv[j][i] == '-' || argv[j][i] == '+')
					i++;
			}
			if (argv[j][i] == ' ')
				flag = 0;
			if (flag == 1 && (argv[j][i] == '-' || argv[j][i] == '+'))
				print_error("arg invalid");
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_check_num(char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (!((argv[j][i] >= '0' && argv[j][i] <= '9') || argv[j][i] == ' '
					|| argv[j][i] == '+' || argv[j][i] == '-'))
				print_error("ERROR ARGUMENT INVALID");
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_check_value(char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 1;
	count = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				count++;
			else
			{
				if (count > 11)
					print_error("NUMBER TOO BIG OR TOO SMALL");
				else
					count = 0;
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (count > 11)
		print_error("number too big or too small");
}

void	ft_check_error(char **argv)
{
	ft_check_num(argv);
	ft_check_value(argv);
	ft_check_signe(argv);
}