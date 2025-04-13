/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:56:02 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/13 18:07:04 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"





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