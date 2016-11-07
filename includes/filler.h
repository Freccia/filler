/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:44:32 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/07 17:59:39 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

#include <math.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	char			player;
	char			adv;
	t_point			m;		// map size
	t_point			p;		// piece size
	t_point			best;
	int				fd;
}					t_env;

void				ft_set_point(t_point *p, int y, int x);
void				ft_get_size(t_point *p, char *line);
void				ft_get_map(t_env *e);
void				ft_place(t_env *e, char map[e->m.y][e->m.x],\
		char pic[e->p.y][e->p.x]);
void				ft_print_best(t_point best);

/*
**		LOG
*/
void	ft_log(t_env *e);
void	ft_log2(t_env *e, char map[e->m.y][e->m.x], \
			char pic[e->m.y][e->m.x], t_point pp, t_point pm, t_point c);
void	ft_log_piece(t_env *e, char pic[e->p.y][e->p.x], char *str);
void	ft_log_map(t_env *e, char map[e->m.y][e->m.x], char *str);
void    ft_log_point(t_env *e, t_point p, char *str);
void	ft_log_best(t_env *e);

#endif
