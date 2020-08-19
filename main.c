/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:24:59 by sbump             #+#    #+#             */
/*   Updated: 2020/02/10 19:26:32 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		size;
	char	**tetriminoline;

	if (check_main(argc, argv[1]) != 0)
	{
		if (check_main(argc, argv[1]) == -1)
			write(1, "error\n", 6);
		else
			write(1, "error\n", 6);
		return (0);
	}
	size = 0;
	fd = open(argv[1], O_RDONLY);
	if (file_read(fd, &size) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	close(fd);
	tetriminoline = ft_for_main(size, argv[1]);
	if (check(size, tetriminoline) != 0)
		write(1, "error\n", 6);
	return (0);
}

char	**ft_for_main(int size, char *argv)
{
	int		fd;
	char	**tetriminoline;

	tetriminoline = malloc(sizeof(char*) * size);
	fd = open(argv, O_RDONLY);
	record_tetriminoline(tetriminoline, fd);
	close(fd);
	return (tetriminoline);
}

int		check_main(int argc, char *argv)
{
	int		fd;
	char	buf[1];
	char	*line;

	if (argc != 2)
		return (-1);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-2);
	if (read(fd, buf, 1) == 0)
	{
		close(fd);
		return (-1);
	}
	else
	{
		while (get_next_line(fd, &line) == 1)
		{
			free(line);
		}
	}
	free(line);
	close(fd);
	return (0);
}
