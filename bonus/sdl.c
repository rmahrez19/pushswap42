/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:30:47 by ramahrez          #+#    #+#             */
/*   Updated: 2025/05/05 21:35:21 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int init_sdl_window(t_sdl *sdl, const char *title)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		print_error("ERREUR SDL INIT");
	sdl->window = SDL_CreateWindow(title,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WIDTH,
			HEIGHT,
			SDL_WINDOW_SHOWN);
	if (!sdl->window)
	{
		fprintf(stderr, "Erreur SDL_CreateWindow : %s\n", SDL_GetError());
		SDL_Quit();
		exit(0);
	}
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
	if (!sdl->renderer)
	{
		fprintf(stderr, "Erreur SDL_CreateRenderer : %s\n", SDL_GetError());
		SDL_DestroyWindow(sdl->window);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
	// Stocker les dimensions dans la structure
	sdl->win_width = WIDTH;
	sdl->win_height = HEIGHT;

	return (1);
}

void	draw_stack_visualizer(t_sdl *sdl, t_stack *stack, int stack_size)
{
	SDL_Rect	rect;
	int			i = 0;
	int			bar_height;

	if (stack_size <= 0)
		return;

	bar_height = sdl->win_height / stack_size;

	// Efface l'écran
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl->renderer);

	while (stack && i < stack_size)
	{
		// ✅ Largeur proportionnelle à moitié d'écran
		int bar_width = (stack->index * (sdl->win_width / 2)) / (stack_size - 1);

		// ✅ Affichage à gauche (x = 0)
		rect.x = 0;
		rect.y = i * bar_height;
		rect.w = bar_width;
		rect.h = bar_height;

		// Couleur dynamique
		SDL_SetRenderDrawColor(sdl->renderer,
			50 + (stack->index * 200 / stack_size),
			100,
			255 - (stack->index * 200 / stack_size),
			255);

		SDL_RenderFillRect(sdl->renderer, &rect);

		stack = stack->next;
		i++;
	}

	SDL_RenderPresent(sdl->renderer);
}


void print(t_stack *a)
{
	t_sdl sdl;
	(void)a;
	init_sdl_window(&sdl, "VIZU");
	draw_stack_visualizer(&sdl, a, str_list(&a));
	while(1);
}