/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:43:22 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/18 15:51:05 by ramahrez         ###   ########.fr       */
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
	log_move("pb");
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
	log_move("pb");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	log_move("pb");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int		content;
	int		index;
	t_stack	*new;

	if (!*stack_a)
		return ;
	content = (*stack_a)->content;
	index = (*stack_a)->index;
	new = ft_malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = content;
	new->index = index;
	ft_add_to_front(stack_b, content);
	(*stack_b)->index = index;
	ft_delone_first(stack_a);
	ft_printf("pb\n");
	log_move("pb");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int		content;
	int		index;
	t_stack	*new;

	if (!*stack_b)
		return ;
	content = (*stack_b)->content;
	index = (*stack_b)->index;
	new = ft_malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = content;
	new->index = index;
	if (!*stack_a)
		ft_create_head_node(stack_a, content);
	else
		ft_add_to_front(stack_a, content);
	(*stack_a)->index = index;
	ft_delone_first(stack_b);
	ft_printf("pa\n");
	log_move("pb");
}

void	ra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || (*stack_a)->next == *stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	ft_printf("ra\n");
	log_move("pb");
}

void	rb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || (*stack_b)->next == *stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	ft_printf("rb\n");
	log_move("pb");
}

void	rra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || (*stack_a)->next == *stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	ft_printf("rra\n");
	log_move("pb");
}

void	rrb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || (*stack_b)->next == *stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	ft_printf("rrb\n");
	log_move("pb");
}
