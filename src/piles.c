/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:42:24 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/18 18:31:42 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int str_list(t_stack *stack_a)
{
	size_t size;

	size = 0
}

void print_list(t_stack **stack_a)
{
	t_stack *current;

	current = *stack_a;
	while(1)
	{
		printf("nombre = |%ld|\n", current->content);
		current = current->next;
		if(current == *stack_a)
			break;
	}
}

void	ft_creat_node(t_stack **stack_a, int n)
{
	t_stack	*prev;
	t_stack	*new;

	if(!*stack_a)
		return ;
	prev = (*stack_a)->prev;
	new = ft_malloc(sizeof(t_stack));
	if(!new)
		return ;
	new->content = n;
	new->next = *stack_a;
	new->prev = prev;
	prev->next = new;
	(*stack_a)->prev = new;
}

void	ft_create_head_node(t_stack **stack_a, int n)
{
	*stack_a = ft_malloc(sizeof(t_stack));
	if (!*stack_a)
		print_error(RED "erreur" RESET);
	(*stack_a)->content = n;
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

	new_stack =ft_malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->content = content;
	new_stack->next = NULL;
	return (new_stack);
}
