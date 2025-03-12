/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:27:16 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/12 17:19:38 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_error(char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (!((argv[j][i] >= '0' && argv[j][i] <= '9')
					|| argv[j][i] <= ' '))
			{
				ft_printf(RED "ERROR ARGUMENT INVALID" RESET);
				exit(1);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_pars_line(char **argv, t_stack stack_a)
{
	int	i;
	int j;

	j = 1;
	i = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			while (argv[j][i] == ' ' && argv[j][i])
				i++;

			i++;
		}
		i = 0;
		j++;
	}
}

t_stack	*ft_pars(char **argv)
{
	t_stack stack_a;
	// ft_pars_line(argv[1]);
	ft_check_error(argv, stack_a);
	return (NULL);
}