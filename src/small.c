#include "../includes/push_swap.h"

void	tri_2(t_stack **stack_a)
{
	int	num_1;
	int	num_2;

	num_1 = (*stack_a)->content;
	num_2 = (*stack_a)->next->content;
	if (num_1 > num_2)
		sa(stack_a);
}

void	tri_3_croissant(t_stack **stack_a)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = (*stack_a)->content;
	num_2 = (*stack_a)->next->content;
	num_3 = (*stack_a)->prev->content;
	if (num_1 > num_2 && num_1 > num_3 && num_2 < num_3)
		ra(stack_a);
	if (num_1 > num_2 && num_1 > num_3 && num_2 > num_3)
	{
		ra(stack_a);
		sa(stack_a);
	}
	if (num_1 > num_2 && num_1 < num_3 && num_2 < num_3)
		sa(stack_a);
	if (num_1 < num_2 && num_1 > num_3 && num_2 > num_3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (num_1 < num_2 && num_1 < num_3 && num_2 > num_3)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	choice_tri(t_stack **stack_a, t_var s_var)
{
	s_var.size_stack = str_list(stack_a);
	if (s_var.size_stack == 2)
		tri_2(stack_a);
	if (s_var.size_stack == 3)
	{
		tri_3_croissant(stack_a);
		// print_list(stack_a);
	}
	else
	{
		tri_list(stack_a, s_var);
	}
}