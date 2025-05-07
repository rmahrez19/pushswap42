/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:29:23 by hectordavro       #+#    #+#             */
/*   Updated: 2025/05/06 15:39:24 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
#define BONUS_H

#include <termios.h>
#include <time.h>
#include "push_swap.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#define WIDTH 1900
#define HEIGHT 1080

typedef struct s_sdl
{
    SDL_Window   *window;
    SDL_Renderer *renderer;
    SDL_Texture  *texture;
    SDL_Surface  *surface;
    SDL_Event     event;
    int           win_width;
    int           win_height;
    bool          running;
}   t_sdl;
int ft_print_loby(void);
void ft_sleep(unsigned int seconds);
char getch(void);
int number_element(void);
char	**ft_random_element(int num_element);



#endif