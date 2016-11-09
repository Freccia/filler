/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:45:46 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/09 16:33:00 by lfabbro          ###   ########.fr       */
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
	ft_set_point(&e.m, 0, 0);
	ft_set_point(&e.p, 0, 0);
	ft_player(&e, line);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			if (!e.m.y && !e.m.x)
				ft_get_size(&e.m, line);
			ft_skip_line();
			ft_get_map(&e);
		}
		free(line);
	}
	return (0);
}
