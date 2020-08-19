/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:57:37 by sbump             #+#    #+#             */
/*   Updated: 2020/02/13 07:11:24 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check(int size, char **tetriminoline)
{
	int	i;
	int	**tetrimino;

	i = 0;
	tetrimino = make_arr(size, 8);
	while (i < size)
	{
		if (check_tetriminoline(tetriminoline[i]) != 0)
			return (-1);
		write_tetrimino(tetriminoline[i], tetrimino[i]);
		i++;
	}
	if (check_tetrimino(tetrimino, size) == 0)
		return (-1);
	paste_to_square(tetrimino, size);
	i = 0;
	while (i < size)
	{
		free(tetriminoline[i]);
		i++;
	}
	free(tetriminoline);
	return (0);
}

int	check_tetrimino(int **tetrimino, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ft_for_check_tetrimino(tetrimino[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_for_check_tetrimino(int *tetrimino)
{
	int		i;
	char	*tetr;
	char	*a;

	tetr = ft_strnew(8);
	i = 0;
	while (i < 8)
	{
		a = ft_itoa(tetrimino[i]);
		tetr[i] = *a;
		i++;
		free(a);
	}
	i = check_char(tetr);
	free(tetr);
	return (i);
}

int	check_tetriminoline(char *tetriminoline)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (tetriminoline[i] != '\0')
	{
		if (tetriminoline[i] != '#' && tetriminoline[i] != '.')
			return (-1);
		if (tetriminoline[i] == '#')
			a++;
		i++;
	}
	if (a != 4)
		return (-1);
	if (i != 16)
		return (-1);
	return (0);
}
