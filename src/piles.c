/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:42:24 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/12 15:36:58 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->content = content;
	new_stack->next = NULL;
	return (new_stack);
}
