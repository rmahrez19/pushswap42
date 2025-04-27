/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:07 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/28 00:23:30 by hectordavro      ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_var	s_var;

	if (ac < 2)
		print_error("ERROR ARGUMENT");
	stack_a = ft_pars(av);
	// print_list(&stack_a);
	if(!verif_tri_c(&stack_a))
		return (0);
	s_var.size_stack = str_list(&stack_a);
	if (s_var.size_stack <= 1)
		exit(0);
	chunk_count(&s_var, stack_a);
	choice_tri(&stack_a, s_var);
	print_list(&stack_a);
	ft_free();
}
