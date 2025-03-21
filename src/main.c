/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:07 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/21 16:14:06 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		size;

	if (ac < 2)
	{
		ft_printf(RED "ERROR NO ARGUMENT" RESET);
		exit(0);
	}
	stack_a = ft_pars(av);
	print_list(&stack_a);
	printf("apres rotation \n");
	size = str_list(&stack_a);
	if(size <= 1)
		exit(0);
	sa(&stack_a);
	print_list(&stack_a);
	ft_free();
}
