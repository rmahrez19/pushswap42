/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:32:43 by ramahrez          #+#    #+#             */
/*   Updated: 2025/03/11 14:01:09 by ramahrez         ###   ########.fr       */
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

t_stack	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);


#endif