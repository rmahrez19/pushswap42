/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:43:22 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/21 16:23:05 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack **stack_a)
{
	int temp;

	temp = (*stack_a)->content ;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	printf("sa");
}

void sb(t_stack **stack_b)
{
	int temp;

	temp = (*stack_b)->content ;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	printf("sb");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	int temp;

	temp = (*stack_a)->content ;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = temp;
	temp = (*stack_b)->content ;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = temp;
	printf("ss");
}