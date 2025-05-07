/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:32:43 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/07 12:15:04 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
#include <sys/wait.h>
#include "bonus.h"
#include <unistd.h>

typedef struct s_stack
{
	int				index;
	long			content;
	struct s_stack	*next;
	struct s_stack	*prev;

}					t_stack;

typedef struct s_var
{
	int				size_stack;
	int				max_value;
	int				min_value;
	int				max_position;
	int				min_position;
	int chunk_count;
	int start;
	int end;

}					t_var;

void				print_error(char *str);
void				ft_check_error(char **argv);
t_stack				*ft_pars(char **argv);
t_stack				*ft_stacknew(int content);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
int					ft_check_double(t_stack **stack, int n);

// liste chainee;

void				print_every_list(t_stack *stack_a, t_stack *stack_b);
void				ft_create_head_node(t_stack **stack_a, int n);
void				ft_creat_node(t_stack **stack, int n);
void				print_list(t_stack **stack_a);
int					str_list(t_stack **stack_a);
void				ft_delone_first(t_stack **stack);
void				init_index(t_stack **stack);
void				ft_add_to_front(t_stack **stack, int n);
void	ft_add_to_back(t_stack **stack, t_stack *new_node);
void	ft_delone_last(t_stack **stack);
// rotaion

void				sa(t_stack **stack_a);
// void				ss(t_stack **stack_a, t_stack **stack_b);
void				sb(t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
// tri
int					verif_tri_c(t_stack **stack);
int					verif_tri_d(t_stack **stack);
void				choice_tri(t_stack **stack_a, t_var s_var);
void				init_position_value(t_stack **stack, t_var *s_var);
void				tri_list(t_stack **stack_a, t_var s_var);
void				tri_3_croissant(t_stack **stack_a);
void	ft_assign_index(t_stack **stack);
void	move_optimized(t_stack **a, t_stack **b, int index_a, t_var s_var);

// utils
void				ft_init(t_stack **stack, t_var *s_var);
void chunk_count(t_var *s_var, t_stack *stack_a);
int find_max_index(t_stack *stack);
void	move_to_top(t_stack **stack, int index, t_var s_var, char c);
int	find_max_index(t_stack *stack);
void	push_back_to_a(t_stack **a, t_stack **b, t_var s_var);

void print(t_stack *a,char **moves);
void ft_moves(char **moves, t_stack **a, t_stack **b);
void log_move(const char *move);
#endif