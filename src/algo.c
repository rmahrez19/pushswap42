/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/13 18:51:55 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void move_to_top(t_stack **stack, int index, t_var s_var)
{
	t_stack *current;
	int steps;

	if(*stack == NULL)
		return ;
	current = *stack;
	s_var.size_stack = str_list(stack);
	current = *stack;
	steps = 0;
	while (current && current->index != index)
	{
		steps++;
		current = current->next;
	}
	if(steps == 0)
		return ;
	if (steps > s_var.size_stack / 2)
	{
		while(steps < s_var.size_stack)
		{
			rra(stack);
			steps++;
		}
	}
	else
	{
		while (steps > 0)
		{
			ra(stack);
			steps--;
		}
	}
}


void	tri_list(t_stack **stack_a, t_var s_var)
{
	t_stack *stack_b;

	
}
