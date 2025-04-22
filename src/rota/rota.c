/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:43:22 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/22 17:04:33 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || (*stack_a)->next == *stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || (*stack_b)->next == *stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	ft_printf("rb\n");
}

void	rra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || (*stack_a)->next == *stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || (*stack_b)->next == *stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	ft_printf("rrb\n");
}
