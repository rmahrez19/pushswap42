/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:07 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/09 16:45:31 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_every_list(t_stack *stack_a, t_stack *stack_b)
{
	printf("stack a\n");
	print_list(&stack_a);
	printf("\n-----------------------------------------------------------------------------------\n");
	printf("\n-----------------------------------------------------------------------------------\n");
	printf("stack_b\n");
	print_list(&stack_b);
	printf("\n-----------------------------------------------------------------------------------\n");
}

void	cost_account(void)
{
	int	i = 0;

	while (get_next_line(0))
		i++;
	printf("coup = %d", i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_var	s_var;

	stack_b = NULL;
	if (ac < 2)
		print_error("ERROR ARGUMENT");
	stack_a = ft_pars(av);
	s_var.size_stack = str_list(&stack_a);
	if (s_var.size_stack <= 1)
		exit(0);
	print_list(&stack_a);
	// 	// choice_tri(&stack_a, s_var);
	pb(&stack_a, &stack_b);
	print_every_list(stack_a, stack_a);
	// pa(&stack_a, &stack_b);
	// print_every_list(stack_a, stack_a);
	ft_free();
	// cost_account();
}
