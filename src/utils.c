/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:37:15 by ramahrez          #+#    #+#             */
/*   Updated: 2025/04/01 16:42:33 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

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
