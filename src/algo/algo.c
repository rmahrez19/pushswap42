/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:12:12 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/07 11:09:45 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Vérifie si un index est dans la plage [start, end] dans la pile
int	has_index_in_range(t_stack *stack, t_var s_var)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		if (current->index >= s_var.start && current->index <= s_var.end)
			return (1);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}

// Trouve le premier index dans la plage [start, end] dans la pile
int	find_index_in_range(t_stack *stack, t_var s_var)
{
	t_stack	*current;

	if (!stack)
		return (-1);
	current = stack;
	while (current)
	{
		if (current->index >= s_var.start && current->index <= s_var.end)
			return (current->index);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (-1);
}

// Pousse tous les éléments d’un chunk de A vers B
// Pousse tous les éléments d’un chunk de A vers B
void	push_chunk_to_b(t_stack **a, t_stack **b, t_var s_var)
{
	int	target_index;

	while (*a && has_index_in_range(*a, s_var))
	{
		target_index = find_index_in_range(*a, s_var);
		if (target_index == -1)
			break ;
		move_to_top(a, target_index, s_var, 'a');
		if (*a) // on s'assure que A n'est pas vide avant de faire pb
			pb(a, b);
	}
}

// Pousse les éléments de B vers A en ordre décroissant
// Pousse les éléments de B vers A en ordre décroissant

void	sort_with_chunks(t_stack **a, t_stack **b, t_var *s_var)
{
	int	chunk_size;
	int	start;
	int	end;
	int	i;

	if (!a || !(*a) || s_var->chunk_count == 0)
	{
		print_error("ERROR: Invalid stack or chunk_count");
		return ;
	}
	chunk_size = s_var->size_stack / s_var->chunk_count;
	start = 0;
	end = chunk_size - 1;
	i = 0;
	while (i < s_var->chunk_count)
	{
		s_var->start = start;
		s_var->end = end;
		push_chunk_to_b(a, b, *s_var);
		start = end + 1;
		end = start + chunk_size - 1;
		if (i == s_var->chunk_count - 2)
			end = s_var->size_stack - 1;
		i++;
	}
}

// Fonction principale de tri
void	tri_list(t_stack **stack_a, t_var s_var)
{
	t_stack	*stack_b;

	if (!stack_a || !(*stack_a))
		return ;
	stack_b = NULL;
	sort_with_chunks(stack_a, &stack_b, &s_var);
	push_back_to_a(stack_a, &stack_b, s_var);
}
