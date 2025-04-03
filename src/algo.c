/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/02 19:56:44 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int verif_tri_c(t_stack **stack)
{
	t_stack *current;

	if(!*stack || !(*stack)->next)
		return 0;
	current = *stack;
	while(1)
	{
		if(current->content > current->next->content)
		{
			ft_printf("pas trier\n");
			return (1);
		}
		current = current->next;
		if(current->next == *stack)
		{
			ft_printf("trier\n");
			return (0);
		}
	}
}

int verif_tri_d(t_stack **stack)
{
	t_stack *current;

	if(!*stack || !(*stack)->next)
		return 0;
	current = *stack;
	while(1)
	{
		if(current->content < current->next->content)
			return (1);
		current = current->next;
		if(current == *stack)
		{
			ft_printf("bien trier");
			return (0);
		}
	}
}


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
			// if(str_list(stack_a) == 3)
			// {
			// 	tri_3_croissant(stack_a);
			// 	break ;
			// }
		}
	while(stack_b)
		pa(stack_a, &stack_b);
		i++;
	}
	print_every_list(*stack_a, stack_b);
}
