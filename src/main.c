/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:31:07 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/22 17:17:48 by ramahrez         ###   ########.fr       */
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

#include <fcntl.h>

void	log_move(const char *move)
{
	int	fd;

	fd = open("moves.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return ;
	write(fd, move, ft_strlen(move));
	write(fd, "\n", 1);
	close(fd);
}

void	cost_account(void)
{
	int	i;

	i = 0;
	while (get_next_line(0))
		i++;
	printf("coup = %d", i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_var	s_var;

	if (ac < 2)
		print_error("ERROR ARGUMENT");
	stack_a = ft_pars(av);
	// print_list(&stack_a);
	s_var.size_stack = str_list(&stack_a);
	if (s_var.size_stack <= 1)
		exit(0);
	chunk_count(&s_var, stack_a);
	choice_tri(&stack_a, s_var);
	print_list(&stack_a);
	ft_free();
}
