/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:45:46 by lfabbro           #+#    #+#             */
/*   Updated: 2016/10/27 17:22:47 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			**malloc_plateau(char *line, int fd)
{
	int		i;
	int		w;
	int		h;

	i = 0;
	w = 0;
	h = 0;
	ft_putstr_fd("line: ", fd);
	ft_putendl_fd(line, fd);
	while (line[i] < '0' || line[i] > '9')
		++i;
	while (line[i] >= '0' && line[i] <= '9')
	{
		w = w * 10 + (line[i] - '0');
		++i;
	}
	ft_putstr_fd("i = ", fd);
	ft_putnbr_fd(i, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd(&line[i], fd);
	while (line[i] < '0' || line[i] > '9')
		++i;
	while (line[i] >= '0' && line[i] <= '9')
	{
		h = h * 10 + (line[i] - '0');
		++i;
	}
	ft_putstr_fd("i = ", fd);
	ft_putnbr_fd(i, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd(&line[i], fd);
	ft_putstr_fd("Plateau width: ", fd);
	ft_putnbr_fd(w, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("Plateau height: ", fd);
	ft_putnbr_fd(h, fd);
	ft_putchar_fd('\n', fd);
	return ((char**)malloc(sizeof(char*) * w));
}

char			**get_plateau(char *line, int fd)
{
	int			i;
	char		**plateau;

	i = 0;
	plateau = malloc_plateau(line, fd);
	free(line);
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "Piece"))
			break ;
		plateau[i] = line;
		ft_putstr_fd("i: ", fd);
		ft_putendl_fd(plateau[i], fd);
		++i;
	}
	return (plateau);
}

int				which_player(void)
{
	char		*line = NULL;

	get_next_line(0, &line);
	if (ft_strstr(line, "exec p1"))
	{
		free(line);
		return (1);
	}
	free(line);
	return (2);
}

int				main(void)
{
	int		player;
	char	*line = NULL;
	int		fd;
	char	**plateau;

	if ((fd = open("filler_log", O_CREAT | O_RDWR, 0744)) < 0)
	{
		perror("filler");
		return (1);
	}
	player = which_player();
	ft_putstr_fd("Player n: ", fd);
	ft_putchar_fd(player + '0', fd);
	ft_putchar_fd('\n', fd);
	while (1)
	{
		if (ft_strstr(line, "Plateau"))
			plateau = get_plateau(line, fd);
		get_next_line(0, &line);
		ft_putendl_fd(line, fd);
	}
	return (0);
}
