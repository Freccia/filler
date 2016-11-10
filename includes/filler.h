/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:44:32 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/10 17:37:22 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
#include "SDL.h"

# define GRID		10

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Renderer	*rend;
}					t_sdl;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	t_sdl			sdl;
	char			player;
	char			adv;
	t_point			m;
	t_point			p;
	t_point			best;
	int				np;
}					t_env;

void				ft_set_point(t_point *p, int y, int x);
void				ft_get_size(t_point *p, char *line);
void				ft_get_map(t_env *e);
void				ft_place(t_env *e, char map[e->m.y][e->m.x],\
		char pic[e->p.y][e->p.x]);
void				ft_print_best(t_point best);

/*
**		SDL
*/
int             sdl_init(t_sdl *sdl);
void			sdl_event(t_sdl *sdl);
void            sdl_draw_grid(t_env *e, t_sdl *sdl);
void			sdl_update_grid(t_env *e, t_sdl *sdl, char map[e->m.y][e->m.x]);

#endif
