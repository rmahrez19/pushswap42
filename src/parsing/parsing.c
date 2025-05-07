/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:27:16 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/07 11:09:59 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_attribute(int n, t_stack **stack) //
{
	if (!(n >= INT_MIN && n <= INT_MAX))
		print_error("NUMBER TOO BIG OR TOO SMALL");
	if (ft_check_double(stack, n))
		print_error("SAME VALUE");
	if (!*stack)
		ft_create_head_node(stack, n);
	else
		ft_creat_node(stack, n);
}

void	ft_pars_line(char **argv, t_stack **stack_a) //
{
	int i;
	int j;

	j = 1;
	i = 0;
	(void)stack_a;
	while (argv[j])
	{
		while (argv[j][i])
		{
			while (argv[j][i] == ' ' && argv[j][i])
				i++;
			if (argv[j][i])
				ft_attribute(ft_atoi(argv[j] + i), stack_a);
			while ((argv[j][i] >= '0' && argv[j][i] <= '9')
				|| (argv[j][i] == '+' || argv[j][i] == '-'))
				i++;
		}
		i = 0;
		j++;
	}
}

t_stack	*ft_pars(char **argv)
{
	t_stack *stack_a;
	stack_a = NULL;
	ft_check_error(argv);
	ft_pars_line(argv, &stack_a);
	ft_assign_index(&stack_a);
	return (stack_a);
}