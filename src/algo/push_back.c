/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:18:45 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/27 22:22:17 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_back_to_a(t_stack **a, t_stack **b, t_var s_var)
{
	int	max_index;

	while (*b)
	{
		max_index = find_max_index(*b);
		move_to_top(b, max_index, s_var, 'b');
		if (*b)
			pa(a, b);
	}
}
