/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:37:15 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/31 23:17:53 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	init_position_value(t_stack **stack, t_var *s_var)
{
	t_stack *curent;
	int 	i;

	i = 2;
	s_var->max_value = (*stack)->content;
	s_var->min_value = (*stack)->content;
	s_var->max_position = 1;
	s_var->min_position = 1;
	curent = *stack;
	while (1)
	{
		curent = curent->next;
		if (curent == *stack || !curent)
			  break ;
		if (s_var->max_value <= curent->content)
		{
			s_var->max_value = curent->content;
			s_var->max_position = i;
		}
		if (s_var->min_value >= curent->content)
		{
			s_var->min_value = curent->content;
			s_var->min_position = i;
		}
		i++;
	}
}
