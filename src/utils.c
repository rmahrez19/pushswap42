/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:37:15 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/18 15:24:42 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

int verif_tri_c(t_stack **stack)
{
	t_stack *current;

	if(!*stack || !(*stack)->next)
		return 0;
	current = *stack;
	while(1)
	{
		if(current->content > current->next->content)
		{
			ft_printf("pas trier\n");
			return (1);
		}
		current = current->next;
		if(current->next == *stack)
		{
			ft_printf("trier\n");
			return (0);
		}
	}
}

int verif_tri_d(t_stack **stack)
{
	t_stack *current;

	if(!*stack || !(*stack)->next)
		return 0;
	current = *stack;
	while(1)
	{
		if(current->content < current->next->content)
			return (1);
		current = current->next;
		if(current == *stack)
		{
			ft_printf("bien trier");
			return (0);
		}
	}
}


void chunk_count(t_var *s_var, t_stack *stack_a)
{
	s_var->size_stack = str_list(&stack_a);
	if(s_var->size_stack <= 100)
		s_var->chunk_count = s_var->size_stack / 5;
	else if(s_var->size_stack <= 500)
		s_var->chunk_count = s_var->size_stack / 10;

}


void	move_to_top(t_stack **stack, int index, t_var s_var)
{
	t_stack	*current;
	int		steps;
	int		size;

	(void)s_var;
	if (!stack || !(*stack) || (*stack)->next == *stack)
		return ;

	size = str_list(stack);
	if (size <= 1)
		return ;

	current = *stack;
	steps = 0;
	while (current->index != index && current->next && current->next != *stack)
	{
		steps++;
		current = current->next;
	}

	// Si l'index est introuvable
	if (current->index != index)
		return ;

	if (steps == 0)
		return ; // Déjà en haut

	// Choix entre ra et rra
	if (steps <= size / 2)
	{
		while (steps-- > 0)
			ra(stack);
	}
	else
	{
		steps = size - steps;
		while (steps-- > 0)
			rra(stack);
	}
}
