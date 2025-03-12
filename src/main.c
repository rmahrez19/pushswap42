/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:07 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/12 16:51:58 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	// t_stack *s_stack;
	// t_stack *new_node1;
	// t_stack *new_node2;
	// int value1 = 42;
	// int value2 = 24;

	// new_node1 = ft_stacknew(value1);
	// new_node2 = ft_stacknew(value2);
	// ft_stackadd_front(&s_stack, new_node1);
	// ft_stackadd_front(&s_stack, new_node2);

	// printf("premier = %d\n", s_stack->content);
	// printf("deuxieme = %d", s_stack->next->content);
	if(ac < 2)
	{
		ft_printf(RED "ERROR NO ARGUMENT" RESET);
		exit(0);
	}
	ft_pars(av);
}
