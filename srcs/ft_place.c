/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:49:57 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/11 17:23:35 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_is_inmap(t_point m, t_point pp, t_point c)
{
	pp.y = pp.y + c.y;
	pp.x = pp.x + c.x;
	if ((pp.x >= 0 && pp.x < m.x) && (pp.y >= 0 && pp.y < m.y))
		return (1);
	return (0);
}

static int	ft_can_fit(t_env *e, char map[e->m.y][e->m.x],
		char pic[e->p.y][e->p.x], t_point c)
{
	t_point	pp;

	e->np = 0;
	pp.y = -1;
	while (++pp.y < e->p.y)
	{
		pp.x = -1;
		while (++pp.x < e->p.x)
		{
			if (pic[pp.y][pp.x] == '*')
			{
				if (ft_is_inmap(e->m, pp, c) && !ft_iswall(e, map, pp, c) &&
						map[pp.y + c.y][pp.x + c.x] != e->adv &&
						map[pp.y + c.y][pp.x + c.x] != (e->adv + 32))
				{
					if (map[pp.y + c.y][pp.x + c.x] == e->player ||
						map[pp.y + c.y][pp.x + c.x] == (e->player + 32))
						++e->np;
				}
				else
					return (0);
			}
		}
	}
	return ((e->np == 1) ? 1 : 0);
}

static int	ft_distance(t_env *e, char pic[e->p.y][e->p.x], t_point j,
		t_point c)
{
	t_point	k;
	t_point	rel;
	int		dist;

	k.y = -1;
	dist = 0;
	while (++k.y < e->p.y)
	{
		k.x = -1;
		while (++k.x < e->p.x)
		{
			if (pic[k.y][k.x] == '*')
			{
				ft_set_point(&rel, k.y + c.y, k.x + c.x);
				dist += ft_abs(j.y - rel.y) + ft_abs(j.x - rel.x);
			}
		}
	}
	return (dist);
}

static int	ft_nearer(t_env *e, char map[e->m.y][e->m.x],
		char pic[e->p.y][e->p.x], t_point c)
{
	t_point	j;
	int		this;
	int		nearer;

	nearer = 99999999;
	j.y = -1;
	while (++j.y < e->m.y)
	{
		j.x = -1;
		while (++j.x < e->m.x)
		{
			if (map[j.y][j.x] == e->adv || map[j.y][j.x] == (e->adv + 32))
			{
				if ((this = ft_distance(e, pic, j, c)) < nearer)
					nearer = this;
			}
		}
	}
	return (nearer);
}

void		ft_place(t_env *e, char map[e->m.y][e->m.x],
		char pic[e->p.y][e->p.x])
{
	t_point	c;
	int		best;
	int		this;

	best = 999999999;
	c.y = -e->p.y;
	while (++c.y < e->m.y)
	{
		c.x = -e->p.x;
		while (++c.x < e->m.x)
		{
			if (ft_can_fit(e, map, pic, c))
			{
				if ((this = ft_nearer(e, map, pic, c)) < best)
				{
					best = this;
					ft_set_point(&e->best, c.y, c.x);
				}
			}
		}
	}
	ft_print_best(e->best);
}
