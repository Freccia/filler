/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:35 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/11 17:13:51 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_skip_line(void)
{
	char	*line;

	get_next_line(0, &line);
	free(line);
}

void	ft_print_best(t_point best)
{
	ft_putnbr(best.y);
	ft_putchar(' ');
	ft_putnbr(best.x);
	ft_putchar('\n');
}

void	ft_set_point(t_point *o, int y, int x)
{
	o->y = y;
	o->x = x;
}

int		ft_iswall(t_env *e, char map[e->m.y][e->m.x], t_point p, t_point c)
{
	int		y;
	int		x;

	y = p.y + c.y;
	x = p.x + c.x;
	if (map[y][x] != '.' && map[y][x] != 'O' && map[y][x] != 'o' &&
		map[y][x] != 'X' && map[y][x] != 'x')
		return (1);
	return (0);
}

void	ft_get_size(t_point *what, char *line)
{
	char	*ptr;

	ptr = ft_strchr(line, ' ');
	what->y = ft_atoi(ptr);
	ptr = ft_strrchr(line, ' ');
	what->x = ft_atoi(ptr);
}
