/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:17:10 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/07 17:59:28 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "filler.h"

void	ft_log2(t_env *e, char map[e->m.y][e->m.x], char pic[e->m.y][e->m.x],\
		t_point pp, t_point pm, t_point c)
{
	ft_putstr_fd("SPOT: ", e->fd);
	ft_putnbr_fd(c.y, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putnbr_fd(c.x, e->fd);
	ft_putchar_fd('\n', e->fd);

	ft_putstr_fd("pp: ", e->fd);
	ft_putnbr_fd(pp.y, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putnbr_fd(pp.x, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putchar_fd(pic[pp.y][pp.x], e->fd);
	ft_putchar_fd('\n', e->fd);

	ft_putstr_fd("pm: ", e->fd);
	ft_putnbr_fd(pm.y, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putnbr_fd(pm.x, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putchar_fd(map[pm.y][pm.x], e->fd);
	ft_putchar_fd('\n', e->fd);

}

void	ft_log_map(t_env *e, char map[e->m.y][e->m.x], char *str)
{
	int		y = -1;
	int		x;

	ft_putendl_fd(str, e->fd);
	while (++y < e->m.y)
	{
		x = -1;
		while (++x < e->m.x)
		{
			ft_putchar_fd(map[y][x], e->fd);
		}
		ft_putchar_fd('\n', e->fd);
	}
}

void	ft_log_piece(t_env *e, char pic[e->p.y][e->p.x], char *str)
{
	int		y = -1;
	int		x;

	ft_putendl_fd(str, e->fd);
	while (++y < e->p.y)
	{
		x = -1;
		while (++x < e->p.x)
		{
			ft_putchar_fd(pic[y][x], e->fd);
		}
		ft_putchar_fd('\n', e->fd);
	}
}

void	ft_log_point(t_env *e, t_point p, char *str)
{
	ft_putstr_fd(str, e->fd);
	ft_putnbr_fd(p.y, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putnbr_fd(p.x, e->fd);
	ft_putchar_fd('\n', e->fd);
}

void	ft_log_best(t_env *e)
{
	ft_putstr_fd("Best:   ", e->fd);
	ft_putnbr_fd(e->best.y, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putnbr_fd(e->best.x, e->fd);
	ft_putchar_fd('\n', e->fd);
}

void	ft_log(t_env *e)
{
	ft_putstr_fd("Map: ", e->fd);
	ft_putnbr_fd(e->m.y, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putnbr_fd(e->m.x, e->fd);
	ft_putchar_fd('\n', e->fd);

	ft_putstr_fd("Pic: ", e->fd);
	ft_putnbr_fd(e->p.y, e->fd);
	ft_putchar_fd(' ', e->fd);
	ft_putnbr_fd(e->p.x, e->fd);
	ft_putchar_fd('\n', e->fd);
}

