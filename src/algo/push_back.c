/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:18:45 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/07 12:13:38 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	get_position(t_stack *stack, int target_index)
{
	int		pos;
	t_stack	*current;

	if (!stack)
		return (-1);
	pos = 0;
	current = stack;
	while (1)
	{
		if (current->index == target_index)
			return (pos);
		current = current->next;
		pos++;
		if (current == stack)
			break ;
	}
	return (-1); // si non trouvé
}

int	get_insert_position(t_stack *stack_b, int index_a)
{
	t_stack	*current;
	int		pos;
	int		best_pos;
	int		best_diff;

	if (!stack_b || !stack_b->next)
		return (0);
	current = stack_b;
	pos = 0;
	best_pos = 0;
	best_diff = 2147483647; // INT_MAX

	while (1)
	{
		if (index_a < current->index &&
			index_a > current->next->index)
			return (pos + 1);
		if (abs(index_a - current->index) < best_diff)
		{
			best_diff = abs(index_a - current->index);
			best_pos = pos + 1;
		}
		current = current->next;
		if (current == stack_b)
			break ;
		pos++;
	}
	return (best_pos % str_list(&stack_b));
}


void	move_optimized(t_stack **a, t_stack **b, int index_a, t_var s_var)
{
	int	pos_a = get_position(*a, index_a);
	int	pos_b = get_insert_position(*b, index_a); // ou selon le plus proche supérieur
	int	size_a = str_list(a);
	int	size_b = str_list(b);

	while (pos_a > 0 && pos_b > 0 && pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		rr(a, b);
		pos_a--;
		pos_b--;
	}
	while (pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		rrr(a, b);
		pos_a++;
		pos_b++;
	}
	// Termine les mouvements restants
	move_to_top(a, pos_a, s_var, 'a');
	move_to_top(b, pos_b, s_var, 'b');
}


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
