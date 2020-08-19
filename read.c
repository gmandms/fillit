/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:53:34 by sbump             #+#    #+#             */
/*   Updated: 2020/02/13 07:21:11 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		file_read(int fd, int *size)
{
	int		n;
	char	*line;

	n = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(line) != 4 && *line != '\0')
			return (-1);
		if (*line)
			n++;
		else
		{
			if (n != 4)
				return (-1);
			n = 0;
			*size += 1;
		}
		free(line);
	}
	if (for_file_read(size, line, n) != 0)
		return (-1);
	free(line);
	if (*size < 1 || *size > 26)
		return (-1);
	return (0);
}

int		for_file_read(int *size, char *line, int n)
{
	if (!(*line) && n == 4)
		*size += 1;
	else
	{
		free(line);
		return (-1);
	}
	return (0);
}

void	record_tetriminoline(char **tetriminoline, int fd)
{
	int		i;
	char	*line;
	char	*one;

	i = 0;
	one = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line)
			one = ft_strjoin_null(one, line);
		else
		{
			tetriminoline[i] = ft_strdup(one);
			ft_strdel(&one);
			i++;
		}
		free(line);
	}
	if (!(*line) && ft_strlen(one) == 16)
		for_record_tetriminoline(tetriminoline, one, i);
	free(line);
}

char	*ft_strjoin_null(char *one, char *line)
{
	char *tmp;

	tmp = one;
	one = ft_strjoin(one, line);
	free(tmp);
	return (one);
}

void	for_record_tetriminoline(char **tetriminoline, char *one, int i)
{
	tetriminoline[i] = ft_strdup(one);
	ft_strdel(&one);
}
