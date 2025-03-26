#include "../includes/push_swap.h"

void	small_tri(t_stack **stack_a, t_stack *stack_b)
{
	int	num_1;
	int	num_2;
	int	num_3;

	(void)stack_b;
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
	if (num_1 < num_2 && num_1)
}
