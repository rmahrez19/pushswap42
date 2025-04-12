/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:56:02 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/12 16:40:46 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_stack	*ft_copy_stack(t_stack *stack)
{
	t_stack	*copy;
	t_stack	*new_node;
	t_stack *head;

	copy = NULL;
	if (!stack)
		return (NULL);

	head = stack;  // Conserve une référence à la tête de la pile originale
	while (stack)
	{
		new_node = ft_malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->content = stack->content;

		// Ajoute chaque élément à la pile copiée
		ft_add_to_front(&copy, new_node->content);

		stack = stack->next;

		// Si on revient à la tête de la pile, on sort de la boucle
		if (stack == head)
			break;
	}

	return (copy);
}


void	ft_sort_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next_temp;
	int		tmp_content;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (temp)
	{
		next_temp = temp->next;
		while (next_temp)
		{
			if (temp->content > next_temp->content)
			{
				// Échange les contenus
				tmp_content = temp->content;
				temp->content = next_temp->content;
				next_temp->content = tmp_content;
			}
			next_temp = next_temp->next;
			if (next_temp == *stack)  // Sortie de boucle pour les piles circulaires
				break;
		}
		temp = temp->next;
		if (temp == *stack)  // Sortie de boucle pour les piles circulaires
			break;
	}
}



void	ft_assign_index(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*sorted_stack;
	int		index;

	// Crée une copie de la pile et trie la copie
	sorted_stack = ft_copy_stack(*stack);  // Crée une copie de la pile
	ft_sort_stack(&sorted_stack);          // Trie la copie de la pile

	// Parcours de la pile originale pour attribuer les indices
	temp = *stack;
	while (temp)
	{
		t_stack	*sorted_temp = sorted_stack;
		index = 0;

		// Trouve la position de l'élément dans la pile triée
		while (sorted_temp)
		{
			if (temp->content == sorted_temp->content)
			{
				temp->index = index;  // Assigne l'indice à l'élément
				break;
			}
			sorted_temp = sorted_temp->next;
			index++;
			if (sorted_temp == sorted_stack)  // Sortie de boucle pour piles circulaires
				break;
		}
		temp = temp->next;
		if (temp == *stack)  // Sortie de boucle pour piles circulaires
			break;
	}
}

int ft_check_double(t_stack **stack, int n)
{
    t_stack *current;

    if(!*stack || !(*stack)->next)
        return (0);
    current = *stack;
    while(1)
    {
        if(n == current->content)
            return (1);
        current = current->next;
        if(current == *stack)
            break ;
    }
    return (0);
}