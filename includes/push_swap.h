/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:32:43 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/18 16:33:22 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	long content;
	struct s_stack *next;
	struct s_stack *prev;

}	t_stack;

void	print_error(char *str);
void	ft_check_error(char **argv);
t_stack *ft_pars(char **argv);
t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **lst, t_stack *new);

// liste chainee;

void	ft_create_head_node(t_stack **stack_a, int n);
void	ft_creat_node(t_stack **stack_a, int n);
void print_list(t_stack **stack_a);

#endif