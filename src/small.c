#include "../includes/push_swap.h"

t_stack *small_tri(t_stack *stack_a, t_stack *stack_b, int  size)
{
    int i;

    i = 0;
    while(i < size)
    {
        if(stack_a->content > stack_a->next->content)
            pb(stack_a, stack_b);
        
    }
    return(NULL);
}