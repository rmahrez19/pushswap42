/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:07:51 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/16 18:29:05 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_copy_stack(t_stack *stack)
{
	t_stack	*copy;
	t_stack	*current;
	t_stack	*new_node;

	if (!stack)
		return (NULL);
	copy = NULL;
	current = stack;

	while (1)
	{
		new_node = ft_malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->content = current->content;
		new_node->index = 0;
		new_node->next = NULL;
		new_node->prev = NULL;
		ft_add_to_back(&copy, new_node);

		current = current->next;
		if (current == stack)
			break;
	}
	return (copy);
}


void	ft_sort_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next_temp;
	int		tmp_content;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (1)
	{
		next_temp = temp->next;
		while (next_temp != *stack)
		{
			if (temp->content > next_temp->content)
			{
				tmp_content = temp->content;
				temp->content = next_temp->content;
				next_temp->content = tmp_content;
			}
			next_temp = next_temp->next;
		}
		temp = temp->next;
		if (temp == *stack)
			break;
	}
}

void	ft_assign_index(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*sorted_stack;
	t_stack	*sorted_temp;
	int		index;

	if (!stack || !*stack)
		return ;
	sorted_stack = ft_copy_stack(*stack);
	ft_sort_stack(&sorted_stack);
	temp = *stack;
	while (1)
	{
		index = 0;
		sorted_temp = sorted_stack;
		while (1)
		{
			if (temp->content == sorted_temp->content)
			{
				temp->index = index;
				break;
			}
			index++;
			sorted_temp = sorted_temp->next;
			if (sorted_temp == sorted_stack)
				break;
		}
		temp = temp->next;
		if (temp == *stack)
			break;
	}
}


int	find_max_index(t_stack *stack)
{
	t_stack	*current;
	int		max;

	if (!stack)
		return (-1);
	current = stack;
	max = current->index;
	while (1)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (max);
}