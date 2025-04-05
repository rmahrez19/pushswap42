/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/04 20:21:33 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void move_to_top(t_stack **stack, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(stack);
		i++;
	}
}


void	tri_list(t_stack **stack_a, t_var s_var)
{
	// t_stack *current;
	t_stack *stack_b;
	// int i;
	// int j;

	stack_b = NULL;
	// i = 0;
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	s_var.size_stack = str_list(stack_a);
	// current = *stack_a;
	while (1)
	{
		ft_init(stack_a, &s_var);
		if( s_var.size_stack == 3)
		{
			tri_3_croissant(stack_a);
			break ;
		}
		move_to_top(stack_a, s_var.min_position);
		pb(stack_a, &stack_b);
	}
	while(stack_b)
		pa(stack_a, &stack_b);
	print_every_list(*stack_a, stack_b);
}
