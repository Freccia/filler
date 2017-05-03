/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:23:20 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/11 17:14:09 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			sdl_quit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->rend);
	SDL_DestroyWindow(sdl->win);
	SDL_Quit();
	exit(0);
}

int				sdl_err(void)
{
	ft_printf("SDL_Error: %s\n", SDL_GetError());
	return (1);
}

void			sdl_event(t_sdl *sdl)
{
	if (sdl->event.type == SDL_QUIT)
		sdl_quit(sdl);
}

void			sdl_clear(t_sdl *sdl)
{
	SDL_SetRenderDrawColor(sdl->rend, 0, 0, 0, 0);
	SDL_RenderClear(sdl->rend);
}

int				sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (sdl_err());
	sdl->win = SDL_CreateWindow("Fillerrrrr",
			//SDL_WINDOWPOS_CENTERED / 3, SDL_WINDOWPOS_CENTERED / 4,
			10, 10,
			640, 480, SDL_WINDOW_SHOWN);
	if (sdl->win == NULL)
		return (sdl_err());
	sdl->rend = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_SOFTWARE);
	return (0);
}
