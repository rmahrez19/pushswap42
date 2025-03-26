/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:32:43 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/26 16:28:21 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	long			content;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

void				print_error(char *str);
void				ft_check_error(char **argv);
t_stack				*ft_pars(char **argv);
t_stack				*ft_stacknew(int content);
void				ft_stackadd_front(t_stack **lst, t_stack *new);

// liste chainee;

void				ft_create_head_node(t_stack **stack_a, int n);
void				ft_creat_node(t_stack **stack_a, int n);
void				print_list(t_stack **stack_a);
int					str_list(t_stack **stack_a);
void				ft_delone_first(t_stack **stack);

// rotaion

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);

// tri

void			small_tri(t_stack **stack_a, t_stack *stack_b);
#endif