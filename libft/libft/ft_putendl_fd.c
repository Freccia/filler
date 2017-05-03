/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:02:48 by lfabbro           #+#    #+#             */
/*   Updated: 2017/03/02 16:23:10 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION:
**     Outputs the string s to the file descriptor fd followed by a ’\n’.
*/

int		ft_putendl_fd(char const *s, int fd)
{
	int		len;

	len = 0;
	if (s)
	{
		len += ft_putstr_fd(s, fd);
		len += ft_putchar_fd('\n', fd);
	}
	return (len);
}
