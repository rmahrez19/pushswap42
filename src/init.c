/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:38:02 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/04 20:21:59 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_position_value(t_stack **stack, t_var *s_var)
{
	t_stack *curent;
	int 	i;

	i = 2;
	s_var->max_value = (*stack)->content;
	s_var->min_value = (*stack)->content;
	s_var->max_position = 1;
	s_var->min_position = 1;
	curent = *stack;
	while (1)
	{
		curent = curent->next;
		if (curent == *stack || !curent)
			  break ;
		if (s_var->max_value <= curent->content)
		{
			s_var->max_value = curent->content;
			s_var->max_position = i;
		}
		if (s_var->min_value >= curent->content)
		{
			s_var->min_value = curent->content;
			s_var->min_position = i;
		}
		i++;
	}
}


int ft_nombre_significatif(int nbr, int place)
{
	char *str;
	int size;
	int temp;
	str =ft_itoa(nbr);
	if(!str)
		print_error(RED "ERROR ALLOCATION" RESET);
	size = ft_strlen(str);

	if(nbr < 0)
	{
		// size--;
		if(place > size)
			return(0);
		temp = str[size - place] -'0';
		return(temp * -1);
	}
	else
	{
		if(place > size)
			return(0);
		temp = str[size - place] -'0';
		return(temp);
	}
}

void init_index(t_stack **stack)
{
    int index = 0;
    t_stack *current;

    current = *stack;
    while(1)
    {
        printf("ok");
        current->index = index;
        current = current->next;
        if(current == (*stack))
            break ;
        index++;
    } 
}


void ft_init(t_stack **stack, t_var *s_var)
{
    init_position_value(stack, s_var);
    s_var->size_stack = str_list(stack);
}
