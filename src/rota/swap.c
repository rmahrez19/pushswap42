/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:02:30 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/22 17:03:37 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a)
{
	int	temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	int	temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}