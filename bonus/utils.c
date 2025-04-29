/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:13:55 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/29 20:58:30 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_tab(char *str)
{
    
    printf(CLEAR "" RESET);
    printf(PURPLE "%-40s■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n", "");
    printf(PURPLE "%-40s■                              ■\n", "");
    printf(PURPLE "%-40s■                              ■\n", "");
    printf(PURPLE "%-40s■             ", "");
    if (str[0] == '_')
        printf("%s_ %s", BLINK, RESET);
    else
        printf(PURPLE "%c ", str[0]);
    if (str[1] == '_')
        printf(PURPLE "%s_ %s", BLINK, RESET);
    else
        printf(PURPLE "%c ", str[1]);    
    if (str[2] == '_')
        printf(PURPLE  "%s_%s", BLINK, RESET);
    else
        printf(PURPLE "%c", str[2]);    

    printf(PURPLE "            ■\n");
    printf(PURPLE "%-40s■                              ■\n", "");
    printf(PURPLE "%-40s■                              ■\n", "");
    printf(PURPLE "%-40s■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n", "");
       
}


int number_element(void)
{
    char c;
    int count;
    char *value;

    value = ft_strdup("___");
    count = 0;
    while(1)
    {
        print_tab(value);
        c = getch();
        if(c >= '0' && c <= '9')
        {
            if(count <= 3)
            {
                value[count] = c;
                count++;          
            }
        }
        if(c == 'd')
        {
            if(count > 0)
            {
                count--;
                value[count] = '_';
            }
        }
        else if(c == '\n')
            break;
    }
    return(ft_atoi(value));
}

void ft_random_element()