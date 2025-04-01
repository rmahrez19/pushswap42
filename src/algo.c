/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/01 18:18:22 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tri_list(t_stack **stack_a, t_var s_var)
{
	t_stack *current;
	t_stack *stack_b;
	int i;
	int j;

	stack_b = NULL;
	i = 0;
	j = 0;
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	s_var.size_stack = str_list(stack_a); 
	current = *stack_a;
	while(i < s_var.size_stack)
	{
		s_var.size_stack = str_list(&stack_b); 	
		while(j < s_var.size_stack )
		{
			if(current->content > current->next->content)
			{
				sa(stack_a);
			}
			current = current->next;
			j++;
			// printf("j = %d\n", j);
		}
		// printf("i = %d\n", i);
		pb(stack_a, &stack_b);
		j = 0;
		i++;
	}
	i = 0;
	print_every_list(*stack_a, stack_b);
	s_var.size_stack = str_list(&stack_b); 
	while(i < s_var.size_stack)
	{
		pa(stack_a, &stack_b);
		i++;
	}
	print_every_list(*stack_a, stack_b);
}