/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:07 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/22 18:00:06 by ramahrez         ###   ########.fr       */
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
	t_stack *stack_b;

	stack_b = NULL;
	int		size;

	if (ac < 2)
	{
		ft_printf(RED "ERROR NO ARGUMENT" RESET);
		exit(0);
	}
	stack_a = ft_pars(av);
	size = str_list(&stack_a);
	if(size <= 1)
		exit(0);
	small_tri(stack_a, stack_b, size);	
	ft_free();
}
