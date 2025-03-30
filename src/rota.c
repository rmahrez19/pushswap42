/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:43:22 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/26 16:24:40 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a)
{
	int	temp;

	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	int	temp;

	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;

	temp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	temp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	ft_printf("ss\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	if (!(*stack_a)->content)
		return ;
	n = (*stack_a)->content;
	if (!*stack_b)
		ft_create_head_node(stack_b, n);
	else
		ft_creat_node(stack_b, n);
	ft_printf("pb\n");
	ft_delone_first(stack_a);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	n;

	if (!(*stack_b)->content)
		return ;
	n = (*stack_a)->content;
	if (!*stack_a)
		ft_create_head_node(stack_a, n);
	else
		ft_creat_node(stack_a, n);
	ft_printf("pa\n");
	ft_delone_first(stack_b);
}

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

void rra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || (*stack_a)->next == *stack_a)
		return ;
	*stack_a = (*stack_a)->prev;

	ft_printf("ra\n");
}

void rrb(t_stack **stack_b)
{
		if (!stack_b || !(*stack_b) || (*stack_b)->next == *stack_b)
		return ;
	*stack_b = (*stack_b)->prev;

	ft_printf("rb\n");
}