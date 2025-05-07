/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:48:44 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/06 15:34:57 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void ft_sleep(unsigned int seconds) 
{
    unsigned int i, j;

    while (seconds--)
    {
        i = 0;
        while (i < 4294967295U) // Boucle pour "perdre du temps"
        {
            j = 0;
            while (j < 1000)
                j++;
            i++;
        }
    }
}