/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <lfabbro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:52:48 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/07 17:59:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "filler.h"

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
