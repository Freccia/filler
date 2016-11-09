/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:44:32 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/09 16:33:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	char			player;
	char			adv;
	int				np;
	t_point			m;
	t_point			p;
	t_point			best;
	int				fd;
}					t_env;

void				ft_set_point(t_point *p, int y, int x);
void				ft_get_size(t_point *p, char *line);
void				ft_get_map(t_env *e);
void				ft_place(t_env *e, char map[e->m.y][e->m.x],\
		char pic[e->p.y][e->p.x]);
void				ft_print_best(t_point best);

#endif
