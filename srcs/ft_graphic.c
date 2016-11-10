/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:26:32 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/10 17:34:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			sdl_draw_grid(t_env *e, t_sdl *sdl)
{
	int		x;
	int		y;

	SDL_SetRenderDrawColor(sdl->rend, 160, 160, 160, 255);
	y = -1;
	x = -1;
	while (++y <= e->m.y)
	{
		SDL_RenderDrawLine(sdl->rend, 0, y * GRID, e->m.x * GRID, y * GRID);
	}
	x = -1;
	while (++x <= e->m.x)
	{
		SDL_RenderDrawLine(sdl->rend, x * GRID, 0, x * GRID, e->m.y * GRID);
	}
	SDL_RenderPresent(sdl->rend);
}

void		sdl_set_rect(SDL_Rect *rect, int x, int y)
{
	rect->w = GRID - 2;
	rect->h = GRID - 2;
	rect->x = x * GRID + 1;
	rect->y = y * GRID + 1;
}

void		sdl_update_grid(t_env *e, t_sdl *sdl, char map[e->m.y][e->m.x])
{
	int			x;
	int			y;
	SDL_Rect	rect;

	y = -1;
	while (++y < e->m.y)
	{
		x = -1;
		while (++x < e->m.x)
		{
			if (map[y][x] != '.')
			{
				if (map[y][x] == e->player || map[y][x] == e->player + 32) 
					SDL_SetRenderDrawColor(sdl->rend, 20, 200, 200, 255);
				if (map[y][x] == e->adv || map[y][x] == e->adv + 32) 
					SDL_SetRenderDrawColor(sdl->rend, 200, 20, 200, 255);
				sdl_set_rect(&rect, x, y);
				SDL_RenderDrawRect(sdl->rend, &rect);
			}
		}
	}
	SDL_RenderPresent(sdl->rend);
}
