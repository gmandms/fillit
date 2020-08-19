/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:49 by sbump             #+#    #+#             */
/*   Updated: 2020/02/10 20:06:08 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compare_all_coords(int **tetrimino, int i, int size_quare)
{
	int			j;
	int			arr[8];
	static int	a;

	j = 0;
	while (j < 8)
	{
		arr[j] = tetrimino[i][j];
		j++;
	}
	if (i == 0 && move_coords(arr, size_quare) == 0)
	{
		if (a == 0)
			a++;
		else
			return (1);
	}
	j = 0;
	while (j < i && i != 0)
	{
		if (compare_coords(tetrimino[i], tetrimino[j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

int		compare_coords(int *t1, int *t2)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (t1[i] == t2[0] && t1[i + 1] == t2[1])
			return (1);
		if (t1[i] == t2[2] && t1[i + 1] == t2[3])
			return (1);
		if (t1[i] == t2[4] && t1[i + 1] == t2[5])
			return (1);
		if (t1[i] == t2[6] && t1[i + 1] == t2[7])
			return (1);
		i += 2;
	}
	return (0);
}

int		min_map(int size)
{
	int	i;

	size *= 4;
	if (size < 1)
		return (0);
	i = 1;
	while (i * i < size)
	{
		i++;
	}
	return (i);
}

char	*record(char *square, int **tetrimino, int size, int size_square)
{
	int		i;
	char	letter;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		record_square(square, tetrimino[i], letter, size_square);
		i++;
		letter++;
	}
	return (square);
}

char	*char_square(int **tetrimino, int size, int size_square)
{
	char	*square;
	int		y;
	int		x;
	int		i;

	i = 0;
	square = malloc(sizeof(char) * (size_square * size_square) + 1);
	y = 0;
	while (y < size_square)
	{
		x = 0;
		while (x < size_square)
		{
			square[i] = '.';
			i++;
			x++;
		}
		y++;
	}
	square[i] = '\0';
	return (record(&square[0], tetrimino, size, size_square));
}
