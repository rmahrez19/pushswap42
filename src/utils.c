/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:37:15 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/28 00:23:03 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

int	verif_tri_c(t_stack **stack)
{
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return (0);
	current = *stack;
	while (1)
	{
		if (current->content > current->next->content)
		{
			return (1);
		}
		current = current->next;
		if (current->next == *stack)
		{
			return (0);
		}
	}
}

int	verif_tri_d(t_stack **stack)
{
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return (0);
	current = *stack;
	while (1)
	{
		if (current->content < current->next->content)
			return (1);
		current = current->next;
		if (current == *stack)
		{
			return (0);
		}
	}
}

void	chunk_count(t_var *s_var, t_stack *stack_a)
{
	s_var->size_stack = str_list(&stack_a);
	if (s_var->size_stack <= 100)
		s_var->chunk_count = s_var->size_stack / 5;
	else if (s_var->size_stack <= 500)
		s_var->chunk_count = s_var->size_stack / 10;
	if (s_var->chunk_count == 0)
		s_var->chunk_count = 1;
}

void	move_to_top_rotation(t_stack **stack, int steps, int size, char c)
{
	if (steps <= size / 2)
	{
		while (steps-- > 0)
		{
			if (c == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		steps = size - steps;
		while (steps-- > 0)
		{
			if (c == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	move_to_top(t_stack **stack, int index, t_var s_var, char c)
{
	t_stack	*current;
	int		steps;
	int		size;

	(void)s_var;
	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;
	size = str_list(stack); // Taille de la pile
	steps = 0;
	current = *stack;

	// Recherche de l'index dans la pile et calcul des étapes nécessaires
	while (current)
	{
		if (current->index == index)
			break;
		steps++;
		current = current->next;
		if (current == *stack) // Si on fait un tour complet
			return ;
	}

	// Si l'élément est déjà au sommet, pas besoin de faire de rotation
	if (steps == 0)
		return ;

	// Déplacement vers le sommet
	move_to_top_rotation(stack, steps, size, c);
}