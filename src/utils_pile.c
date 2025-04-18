/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:56:02 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/18 14:00:29 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	ft_delone_last(t_stack **stack)
{
	t_stack *last;

	if (!stack || !(*stack))
		return ;
	last = (*stack)->prev;
	if (last == *stack)
	{
		*stack = NULL;
		return ;
	}
	last->prev->next = *stack;
	(*stack)->prev = last->prev;
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