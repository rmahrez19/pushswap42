/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:38:02 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/07 11:32:44 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_position_value(t_stack **stack, t_var *s_var)
{
	t_stack	*cur;
	int		i;
	int		val;

	i = 2;
	val = (*stack)->content;
	s_var->max_value = val;
	s_var->min_value = val;
	s_var->max_position = 1;
	s_var->min_position = 1;
	cur = *stack;
	while ((cur = cur->next) && cur != *stack)
	{
		if (cur->content >= s_var->max_value)
		{
			s_var->max_value = cur->content;
			s_var->max_position = i;
		}
		if (cur->content <= s_var->min_value)
		{
			s_var->min_value = cur->content;
			s_var->min_position = i;
		}
		i++;
	}
}

void	init_index(t_stack **stack)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = *stack;
	while (1)
	{
		current->index = index;
		current = current->next;
		if (current == *stack)
			break ;
		index++;
	}
}

void	ft_init(t_stack **stack, t_var *s_var)
{
	init_position_value(stack, s_var);
	s_var->size_stack = str_list(stack);
}
