/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:43:35 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/10 18:59:08 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_skip_line(void)
{
	char	*line;

	get_next_line(0, &line);
	free(line);
}

int		ft_is_inmap(t_point m, t_point pp, t_point c)
{
	pp.y = pp.y + c.y;
	pp.x = pp.x + c.x;
	if ((pp.x >= 0 && pp.x < m.x) && (pp.y >= 0 && pp.y < m.y))
		return (1);
	return (0);
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

void	ft_get_size(t_point *what, char *line)
{
	char	*ptr;

	ptr = ft_strchr(line, ' ');
	what->y = ft_atoi(ptr);
	ptr = ft_strrchr(line, ' ');
	what->x = ft_atoi(ptr);
}
