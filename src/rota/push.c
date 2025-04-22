/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:02:26 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/22 17:04:30 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int content;
	int index;
	t_stack *new;

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
}