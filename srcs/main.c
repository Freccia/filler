/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:32:27 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/10 17:37:20 by lfabbro          ###   ########.fr       */
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
		if (get_next_line(0, &line) > 0)
		{
			if (ft_strstr(line, "Plateau"))
			{
				if (!e.m.y && !e.m.x)
				{
					ft_get_size(&e.m, line);
					SDL_SetWindowSize(e.sdl.win, e.m.x * GRID + 1, e.m.y * GRID + 1);
					sdl_draw_grid(&e, &e.sdl);
				}
				ft_skip_line();
				ft_get_map(&e);
			}
		}
		free(line);
	}
	return (0);
}
