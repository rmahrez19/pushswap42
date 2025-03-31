#include "../includes/push_swap.h"

void tri_2(t_stack **stack_a)
{
	int	num_1;
	int	num_2;

	num_1 = (*stack_a)->content;
	num_2 = (*stack_a)->next->content;
	if(num_1 > num_2)
		sa(stack_a);
}

void	tri_3(t_stack **stack_a)
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
	if( num_1 < num_2 && num_1 > num_3 && num_2 > num_3)
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

void tri_5(t_stack **stack_a, t_stack *stack_b, t_var *s_var)
{
	int i = 0;

	while(i < 2)
	{
		init_position_value(stack_a, s_var);
		if (s_var->min_position == 1)
			pb(stack_a, &stack_b);

		else if (s_var->min_position == 2)
		{
			sa(stack_a);
			pb(stack_a, &stack_b);
		}
		else if (s_var->min_position == 3)
		{
			sa(stack_a);
			sa(stack_a);
			pb(stack_a, &stack_b);
		}
		else if (s_var->min_position == 4)
		{
			rra(stack_a);
			rra(stack_a);
			pb(stack_a, &stack_b);
		}
		else if (s_var->min_position == 5)
		{
			rra(stack_a);
			pb(stack_a, &stack_b);
		}
		i++;
	}
	tri_3(stack_a);
	pa(stack_a, &stack_b);
	pa(stack_a, &stack_b);
}

void choice_tri(t_stack **stack_a, t_stack *stack_b, t_var s_var)
{
	(void)stack_b;
	if (s_var.size_stack == 2)
		tri_2(stack_a);
	if(s_var.size_stack == 3)
		tri_3(stack_a);
	else
	{
		tri_5(stack_a, stack_b, &s_var);
	}
}