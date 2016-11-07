/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:42:25 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/07 17:59:38 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "filler.h"
#include <sys/select.h>

/*
void ft_sleep(unsigned long nsec) 
{
	struct timespec delay = { nsec / 1, nsec % 3 };
	pselect(0, NULL, NULL, NULL, &delay, NULL);
}
*/

int		ft_is_inmap(t_point m, t_point pm)
{
	if ((pm.x >= 0 && pm.x < m.x) && (pm.y >= 0 && pm.y < m.y))
		return (1);
	return (0);
}

int		ft_can_fit(t_env *e, char map[e->m.y][e->m.x], char pic[e->p.y][e->p.x],
		t_point c)
{
	t_point	pp;
	t_point	pm;
	int		np;

	np = 0;
	pp.y = -1;
	pm.y = c.y;
	while (++pp.y < e->p.y)
	{
		pp.x = -1;
		pm.x = c.x;
		while (++pp.x < e->p.x)
		{
			if (pic[pp.y][pp.x] == '*')
			{
				if (ft_is_inmap(e->m, pm) && map[pm.y][pm.x] != e->adv && 
						map[pm.y][pm.x] != (e->adv + 32))
				{
					if (map[pm.y][pm.x] == e->player || 
							map[pm.y][pm.x] == (e->player + 32))
					{
						++np;
						//ft_log2(e, map, pic, pp, pm, c);
					}
				}
				else
					return (0);
			}
			++pm.x;
		}
		++pm.y;
	}
	return ((np == 1) ? 1 : 0);
}

int		ft_distance(t_env *e, char pic[e->p.y][e->p.x], t_point j, t_point c)
{
	/*
	double	x;
	double	y;

	y = fabs((double)(j.y - c.y));
	y = y * y;
	x = fabs((double)(j.x - c.x));
	x = x * x;
	return ((int)(sqrt(x + y)));
	*/
	int		y = -1;
	int		x;
	int		dist = 0;;
	int	z, k;

	while (++y < e->p.y)
	{
		x = -1;
		while (++x < e->p.x)
		{
			if (pic[y][x] == '*')
			{
				z = ft_abs(j.y - c.y + y);
				k = ft_abs(j.x - c.x + x);
				dist += (z + k);
			}
		}
	}
	return (dist);
}

int		ft_nearer(t_env *e, char map[e->m.y][e->m.x], char pic[e->p.y][e->p.x],
		t_point c)
{
	t_point	j;
	int		this;

	this = 0;
	j.y = -1;
	while (++j.y < e->m.y)
	{
		j.x = -1;
		while (++j.x < e->m.x)
		{
			if (map[j.y][j.x] == e->adv || map[j.y][j.x] == (e->adv + 32))
			{

				ft_log_point(e, j, "ADV:      ");

				return (ft_distance(e, pic, j, c));
			}
		}
	}
	return (this);
}

void	ft_place(t_env *e, char map[e->m.y][e->m.x], char pic[e->p.y][e->p.x])
{
	t_point	c;
	int		best;
	int		this;

	//ft_sleep(1);

	best = 1999999999;
	c.y = -e->p.y;

	ft_log(e);
	ft_log_piece(e, pic, "Piece copy:");
	ft_log_map(e, map, "Map copy:");

	while (++c.y < e->m.y)
	{
		c.x = -e->p.x;
		while (++c.x < e->m.x)
		{
			if (ft_can_fit(e, map, pic, c))
			{
				if ((this = ft_nearer(e, map, pic, c)) < best)
					ft_set_point(&e->best, c.y, c.x);
			}
		}
	}

	ft_log_best(e);

	ft_print_best(e->best);
}