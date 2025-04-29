/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loby.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hectordavrou <hectordavrou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:27:19 by hectordavro       #+#    #+#             */
/*   Updated: 2025/04/29 12:33:36 by hectordavro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/push_swap.h"

void print_next(const char *color1, const char *color2)
{
    printf("%s■                             ■\n", color2);  // Côté du rectangle 2
    if (ft_strncmp(GREEN, color1, 10) == 0)
        printf("%s            ■       %s%-24s%s%s■", color1, BLINK, "valeur aléatoire", RESET, color1); // Texte centré rectangle 1
    else
        printf("%s            ■      %s%-12s%s■", color1, "valeur aléatoire", RESET, color1); // Texte centré rectangle 1
    printf("                      ");
    if (ft_strncmp(GREEN, color2, 10) == 0)
        printf("%s■     %s%-24s%s%s■\n", color2, BLINK, "valeur en argument", RESET, color2); // Texte centré rectangle 2
    else
        printf("%s■     %s%-10s%s■\n", color2, "valeur en argument", RESET, color2); // Texte centré rectangle 2   
    printf("%s            ■                              ■", color1);  // Côté du rectangle 1
    printf("                      ");
    printf("%s■                             ■\n", color2);  // Côté du rectangle 2
    printf("%s            ■                              ■", color1);  // Côté du rectangle 1
    printf("                      ");
    printf("%s■                             ■\n", color2);  // Côté du rectangle 2
    printf("%s            ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", color1);  // Bord du rectangle 1
    printf("                      ");
    printf("%s■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n", color2);  // Bord du rectangle 2
    printf(RESET);  // Reset du style 
}

void ft_print_choice_duo(const char *color1, const char *color2)
{
    printf("%s            ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", color1);  // Bord du rectangle 1
    printf("                      ");
    printf("%s■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n", color2);  // Bord du rectangle 2
    printf("%s            ■                              ■", color1);  // Côté du rectangle 1
    printf("                      ");
    printf("%s■                             ■\n", color2);  // Côté du rectangle 2
    printf("%s            ■                              ■", color1);  // Côté du rectangle 1
    printf("                      ");
    print_next(color1, color2);
}

int ft_print_loby(void)
{
    int choice;
    int     c;
    choice = 1;
    while(1)
    {
        printf(CLEAR);
        if(choice == 1)
         ft_print_choice_duo(GREEN, PURPLE);
        else
            ft_print_choice_duo(PURPLE, GREEN);
        c = getch();
        if (c == 'a')
            choice = 1;
        else if (c == 'd')
            choice = 2;
        else if (c == '\n') // Entrée pour valider
            break;  
    }
    return (choice);
}
