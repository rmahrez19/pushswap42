/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:58:36 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/07 11:19:32 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(char *str)
{
	ft_free();
	printf(RED "%s\n" RESET, str);
	exit(0);
}

void	ft_check_signe(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if ((argv[j][i] == '+' || argv[j][i] == '-') && (i == 0 || argv[j][i
					- 1] == ' '))
			{
				if (!(argv[j][i + 1] >= '0' && argv[j][i + 1] <= '9'))
					print_error("Invalid sign usage");
			}
			else if (argv[j][i] == '+' || argv[j][i] == '-')
			{
				print_error("Invalid sign placement");
			}
			i++;
		}
		j++;
	}
}

void	ft_check_num(char **argv)
{
	int		i;
	int		j;

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

	j = 1;
	while (argv[j])
	{
		i = 0;
		count = 0;
		if (argv[j][i] == '-' || argv[j][i] == '+')
			i++;
		while (argv[j][i])
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				count++;
			else
				print_error("INVALID CHARACTER IN NUMBER");
			i++;
		}
		if (count > 12)
			print_error("NUMBER TOO BIG OR TOO SMALL");
		j++;
	}
}

void	ft_check_error(char **argv)
{
	ft_check_num(argv);
	ft_check_value(argv);
	ft_check_signe(argv);
}
