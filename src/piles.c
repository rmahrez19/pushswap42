/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:42:24 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/03 20:21:53 by ramahrez         ###   ########.fr       */
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
		printf("nombre = |%ld|\n", current->content);
		printf("index = |%d|\n", current->index);
		current = current->next;
		if (current == *stack_a || !current)
			break ;
	}
}

void	ft_creat_node(t_stack **stack_a, int n, int index)
{
	t_stack	*prev;
	t_stack	*new;

	if (!*stack_a || !stack_a)
		return ;
	prev = (*stack_a)->prev;
	new = ft_malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = n;
	new->index = index;
	new->next = *stack_a;
	new->prev = prev;
	prev->next = new;
	(*stack_a)->prev = new;
}

void	ft_create_head_node(t_stack **stack_a, int n, int index)
{
	*stack_a = ft_malloc(sizeof(t_stack));
	if (!*stack_a)
		print_error(RED "erreur" RESET);
	(*stack_a)->content = n;
	(*stack_a)->index = index;
	(*stack_a)->prev = *stack_a;
	(*stack_a)->next = *stack_a;
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
	}
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
	t_stack *first;
	t_stack *last;

	if (!stack || !(*stack))
		return ;
	first = *stack;
	if (first->next == *stack)
	{
		// free(first);
		*stack = NULL;
		return ;
	}
	last = *stack;
	while (last->next != *stack)
		last = last->next;
	*stack = first->next;
	last->next = *stack;
}