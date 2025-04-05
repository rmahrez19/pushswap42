/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:37:15 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/04 16:39:57 by hectordavro      ###   ########.fr       */
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


