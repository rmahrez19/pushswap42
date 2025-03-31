/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:37:15 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/31 19:58:43 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	init_position_value(t_stack **stack, t_var *s_var)
{
	t_stack *curent;
	int 	i;

	i = 1;
	s_var->max_value = (*stack)->content;
	curent = *stack;
	while (1)
	{
		curent = curent->next;
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
		if (curent = *stack || !curent)
			break ;
		i++;
	}
}