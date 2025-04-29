/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:48:44 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/29 11:01:38 by hectordavro      ###   ########.fr       */
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