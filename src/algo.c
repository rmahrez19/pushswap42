/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/01 18:18:22 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tri_list(t_stack **stack_a, t_var s_var)
{
	int position;
	t_stack *current;

	current = *stack_a;
	position = 0;
	(void)s_var;
	// while (position < 10)
	// {
		while (1)
		{
			if (current->content > current->next->content)
			{
				current = *stack_a;
				sa(stack_a);

			}
			else
			{
				current = current->next;
				if (current->next == *stack_a)
				break ;
			}
		}

	// }
}