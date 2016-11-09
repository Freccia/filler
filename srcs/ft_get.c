/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:46 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/09 16:32:55 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_get_algo(t_env *e, char map[e->m.y][e->m.x])
{
	int			y;
	int			x;

	y = -1;
	while (++y < e->m.y)
	{
		x = -1;
		while (++x < e->m.x)
		{
			if (map[y][x] != '.')
			{
				e->algo = (map[y][x] == e->player) ? 1 : 2;
				return ;
			}
		}
	}
}

static void		ft_get_piece(t_env *e, char map[e->m.y][e->m.x])
{
	char		pic[e->p.y][e->p.x];
	char		*line;
	int			y;
	int			x;

	line = NULL;
	y = -1;
	while (++y < e->p.y)
	{
		x = -1;
		get_next_line(0, &line);
		while (++x < e->p.x)
		{
			pic[y][x] = line[x];
		}
		free(line);
	}
	if (!e->algo)
		ft_get_algo(e, map);
	ft_place(e, map, pic);
}

void			ft_get_map(t_env *e)
{
	char		map[e->m.y][e->m.x];
	char		*line;
	int			y;
	int			x;

	line = NULL;
	y = -1;
	while (++y < e->m.y)
	{
		x = -1;
		get_next_line(0, &line);
		while (++x < e->m.x)
		{
			map[y][x] = line[x + 4];
		}
		free(line);
	}
	get_next_line(0, &line);
	ft_get_size(&e->p, line);
	free(line);
	ft_get_piece(e, map);
}
