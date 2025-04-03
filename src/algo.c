/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/03 20:22:04 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void move_to_top(t_stack **stack, int index)
// {

// }


void	tri_list(t_stack **stack_a, t_var s_var)
{
	t_stack *current;
	t_stack *stack_b;
	int i;
	int j;

	stack_b = NULL;
	i = 0;
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	s_var.size_stack = str_list(stack_a);
	current = *stack_a;
	while(i < s_var.size_stack)
	{
		j = 0;
		while(j < s_var.size_stack)
		{
			current = (*stack_a);
			if(current->content > current->next->content)
				sa(stack_a);
				// break ;
			pb(stack_a, &stack_b);
			j++;
		}
		while(stack_b)
			pa(stack_a, &stack_b);
		i++;
	}
	print_every_list(*stack_a, stack_b);
}
