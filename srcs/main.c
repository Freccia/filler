/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:45:46 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/10 00:28:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_player(t_env *e, char *line)
{
	get_next_line(0, &line);
	e->player = (ft_strstr(line, "p1")) ? 'O' : 'X';
	e->adv = (e->player == 'O') ? 'X' : 'O';
	free(line);
}

static void		ft_skip_line(void)
{
	char	*line;

	get_next_line(0, &line);
	free(line);
}

void			sdl_quit(t_sdl *sdl)
{
	SDL_DestroyWindow(sdl->win);
	SDL_Quit();
}

int				sdl_err(void)
{
	ft_printf("SDL_Error: %s\n", SDL_GetError());
	return (1);
}

int				sdl_init(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (sdl_err());
	sdl->win = SDL_CreateWindow("Filler",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			640, 480, SDL_WINDOW_RESIZABLE);
	if (sdl->win == NULL)
		return (sdl_err());
	sdl->surf = SDL_GetWindowSurface(sdl->win);
	SDL_FillRect(sdl->surf, NULL, SDL_MapRGB(sdl->surf->format, 0x00, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(sdl->win);
	SDL_Delay(2000);
	return (0);
}

void			sdl_event(t_sdl *sdl)
{
	if (sdl->event.type == SDL_QUIT)
		sdl_quit(sdl);
}

int				main(void)
{
	char	*line;
	t_env	e;
	line = NULL;

	if (sdl_init(&e.sdl))
		return (1);
	ft_set_point(&e.m, 0, 0);
	ft_set_point(&e.p, 0, 0);
	ft_player(&e, line);
	while (1)
	{
		if (SDL_PollEvent(&e.sdl.event))
			sdl_event(&e.sdl);
		get_next_line(0, &line);
		if (ft_strstr(line, "Plateau"))
		{
			if (!e.m.y && !e.m.x)
				ft_get_size(&e.m, line);
			ft_skip_line();
			ft_get_map(&e);
		}
		free(line);
	}
	sdl_quit(&e.sdl);
	return (0);
}
