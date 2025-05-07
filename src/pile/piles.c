/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:42:24 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/07 11:21:11 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_create_head_node(t_stack **stack_a, int n)
{
	*stack_a = ft_malloc(sizeof(t_stack));
	if (!*stack_a)
		print_error(RED "erreur" RESET);
	(*stack_a)->content = n;
	(*stack_a)->prev = *stack_a;
	(*stack_a)->next = *stack_a;
}

void	ft_add_to_front(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*last;

	new = ft_malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = n;
	if (!*stack)
	{
		new->next = new;
		new->prev = new;
		*stack = new;
		return ;
	}
	last = (*stack)->prev;
	new->next = *stack;
	new->prev = last;
	last->next = new;
	(*stack)->prev = new;
	*stack = (*stack)->prev;
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_stack;

	new_stack = ft_malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->content = content;
	new_stack->next = NULL;
	return (new_stack);
}

void	ft_delone_first(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack))
		return ;
	first = *stack;
	if (first->next == *stack)
	{
		*stack = NULL;
		return ;
	}
	last = first->prev;
	*stack = first->next;
	last->next = *stack;
	(*stack)->prev = last;
}

void	ft_add_to_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		last = (*stack)->prev;
		last->next = new_node;
		new_node->prev = last;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}
