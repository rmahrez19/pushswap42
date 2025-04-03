/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:07 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/02 19:41:02 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_every_list(t_stack *stack_a, t_stack *stack_b)
{
	printf("stack a\n");
	print_list(&stack_a);
	printf("\n-----------------------------------------------------------------------------------\n");
	printf("\n-----------------------------------------------------------------------------------\n");
	printf("stack_b");
	print_list(&stack_b);
	printf("\n-----------------------------------------------------------------------------------\n");

}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_var s_var;

	if (ac < 2)
		print_error("ERROR ARGUMENT");
	stack_a = ft_pars(av);
	s_var.size_stack = str_list(&stack_a);
	if(s_var.size_stack <= 1)
		exit(0);
	choice_tri(&stack_a, s_var);
	ft_free();
}
