/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:09:45 by lfabbro           #+#    #+#             */
/*   Updated: 2017/03/02 16:25:24 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**      Outputs the integer n to the file descriptor fd
*/

static int	ft_nbrlen(int n)
{
	int		l;

	l = 0;
	while (n)
	{
		n /= 10;
		++l;
	}
	return (l);
}

int		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				l;

	nb = n;
	l = ft_nbrlen(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
	return (l);
}
