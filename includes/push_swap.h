/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:32:43 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/12 16:49:44 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int content;
	struct s_stack *next;

}	t_stack;



t_stack *ft_pars(char **argv);
t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **lst, t_stack *new);


#endif