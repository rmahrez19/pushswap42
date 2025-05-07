/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:15:09 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/07 11:17:35 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tri_2(t_stack **stack_a)
{
	int	num_1;
	int	num_2;

	num_1 = (*stack_a)->content;
	num_2 = (*stack_a)->next->content;
	if (num_1 > num_2)
		sa(stack_a);
}

void	tri_3_croissant(t_stack **stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stack_a)->content;
	n2 = (*stack_a)->next->content;
	n3 = (*stack_a)->prev->content;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(stack_a);
	else if (n1 > n2 && n2 > n3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(stack_a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(stack_a);
}

void	choice_tri(t_stack **stack_a, t_var s_var)
{
	s_var.size_stack = str_list(stack_a);
	if (s_var.size_stack == 2)
		tri_2(stack_a);
	if (s_var.size_stack == 3)
	{
		tri_3_croissant(stack_a);
	}
	else
	{
		tri_list(stack_a, s_var);
	}
}
