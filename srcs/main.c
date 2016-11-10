/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:32:27 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/10 20:03:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_player(t_env *e)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	e->player = (ft_strstr(line, "p1")) ? 'O' : 'X';
	e->adv = (e->player == 'O') ? 'X' : 'O';
	free(line);
}

static int		ft_init(t_env *e)
{
	if (sdl_init(&e->sdl))
		return (1);
	ft_set_point(&e->m, 0, 0);
	ft_set_point(&e->p, 0, 0);
	ft_player(e);
	e->line = NULL;
	return (0);
}

int				main(void)
{
	t_env	e;

	if (ft_init(&e))
		return (1);
	while (1)
	{
		if (SDL_PollEvent(&e.sdl.event))
			sdl_event(&e.sdl);
		if (get_next_line(0, &e.line) > 0)
		{
			if (ft_strstr(e.line, "Plateau"))
			{
				if (!e.m.y && !e.m.x)
				{
					ft_get_size(&e.m, e.line);
					SDL_SetWindowSize(e.sdl.win, e.m.x * GRID + 1, \
							e.m.y * GRID + 1);
					sdl_draw_grid(&e, &e.sdl);
				}
				ft_get_map(&e);
			}
		}
		free(e.line);
	}
	return (0);
}
