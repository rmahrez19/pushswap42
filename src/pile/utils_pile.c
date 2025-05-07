/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:56:02 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/07 11:21:54 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	str_list(t_stack **stack_a)
{
	size_t	size;
	t_stack	*current;

	if (!*stack_a)
		return (0);
	current = *stack_a;
	size = 1;
	while (1)
	{
		current = current->next;
		if (current == *stack_a)
			break ;
		size++;
	}
	return (size);
}

void	print_list(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	if (*stack_a == NULL)
		return ;
	while (1)
	{
		ft_printf("nombre = |%ld|\n", current->content);
		current = current->next;
		if (current == *stack_a || !current)
			break ;
	}
}

void	ft_creat_node(t_stack **stack_a, int n)
{
	t_stack	*prev;
	t_stack	*new;

	if (!stack_a || !(*stack_a))
		return ;
	prev = (*stack_a)->prev;
	new = ft_malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = n;
	new->next = *stack_a;
	new->prev = prev;
	prev->next = new;
	(*stack_a)->prev = new;
}

void	ft_delone_last(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !(*stack))
		return ;
	last = (*stack)->prev;
	if (last == *stack)
	{
		*stack = NULL;
		return ;
	}
	last->prev->next = *stack;
	(*stack)->prev = last->prev;
}

int	ft_check_double(t_stack **stack, int n)
{
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return (0);
	current = *stack;
	while (1)
	{
		if (n == current->content)
			return (1);
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (0);
}
