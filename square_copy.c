/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:29:19 by sbump             #+#    #+#             */
/*   Updated: 2020/02/10 19:54:11 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	paste_to_square(int **tetrimino, int size)
{
	int *square;
	int size_square;
	int i;

	size_square = min_map(size);
	square = make_square(size_square);
	paste(square, tetrimino, size, size_square);
	i = 0;
	while (i < size)
	{
		free(tetrimino[i]);
		i++;
	}
	free(tetrimino);
}

void	paste(int *square, int **tetrimino, int size, int size_square)
{
	char	*p_square;

	size_square = paste_tetrimino(square, tetrimino, size, size_square);
	p_square = char_square(tetrimino, size, size_square);
	print_square(p_square, size_square);
	free(p_square);
}

int		paste_tetrimino(int *s, int **tetrimino, int size, int size_square)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i > -1 && check_coords(s, tetrimino[i], size_square) == 1)
			i = for_paste_tetrimino(tetrimino, i, size_square);
		else
		{
			free(s);
			s = make_square(++size_square);
			i = 0;
		}
	}
	free(s);
	return (size_square);
}

int		for_paste_tetrimino(int **tetrimino, int i, int size_square)
{
	if (compare_all_coords(tetrimino, i, size_square) == 1)
	{
		while (i > -1 && if_move_coords(tetrimino[i], size_square) == 0)
		{
			move_coords(tetrimino[i], size_square);
			i--;
		}
		if (i != -1 && if_move_coords(tetrimino[i], size_square) == 1)
			move_coords(tetrimino[i], size_square);
	}
	else
		i++;
	return (i);
}

int		*make_square(int size)
{
	int *square;
	int x;
	int y;
	int i;

	square = malloc(sizeof(int) * ((size * size) * 2));
	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			square[i] = x;
			square[i + 1] = y;
			i += 2;
			x++;
		}
		y++;
	}
	return (square);
}
