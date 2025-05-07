/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:24:13 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/07 11:06:30 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

#include "../includes/bonus.h"

void ft_moves(char **moves, t_stack **a, t_stack **b)
{
	static int i = 0;

	if (!moves[i])
		return;

	if (ft_strncmp(moves[i], "sa", 4) == 0)
		sa(a);
	else if (ft_strncmp(moves[i], "sb", 4) == 0)
		sb(b);
	// else if (ft_strncmp(moves[i], "ss", 4) == 0)
	// 	ss(a, b);
	else if (ft_strncmp(moves[i], "ra", 4) == 0)
		ra(a);
	else if (ft_strncmp(moves[i], "rb", 4) == 0)
		rb(b);
	// else if (ft_strncmp(moves[i], "rr", 4) == 0)
	// 	rr(a, b);
	else if (ft_strncmp(moves[i], "rra", 4) == 0)
		rra(a);
	else if (ft_strncmp(moves[i], "rrb", 4) == 0)
		rrb(b);
	// else if (ft_strncmp(moves[i], "rrr", 4) == 0)
	// 	rrr(a, b);
	else if (ft_strncmp(moves[i], "pb", 4) == 0)
		pb(a, b);
	else if (ft_strncmp(moves[i], "pa", 4) == 0)
		pa(a, b);

	i++;
}

