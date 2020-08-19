/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:13:17 by sbump             #+#    #+#             */
/*   Updated: 2020/02/10 20:16:40 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		move_coords(int *tetrimino, int size_square)
{
	int i;

	i = 0;
	if (max_x(tetrimino) < (size_square - 1))
	{
		tetrimino_while(tetrimino, i);
		return (1);
	}
	else
	{
		i = 1;
		nullified_x(tetrimino);
		if (max_y(tetrimino) < (size_square - 1))
		{
			tetrimino_while(tetrimino, i);
			return (1);
		}
		else
			nullified_y(tetrimino);
	}
	return (0);
}

int		if_move_coords(int *tetrimino, int size_square)
{
	if (max_x(tetrimino) < (size_square - 1))
		return (1);
	else
	{
		if (max_y(tetrimino) < (size_square - 1))
			return (1);
	}
	return (0);
}

void	nullified_x(int *tetrimino)
{
	int arr[4];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		arr[i] = tetrimino[j];
		i++;
		j += 2;
	}
	while (i > 0)
	{
		j -= 2;
		tetrimino[j] -= move_to_null(arr);
		i--;
	}
}

void	nullified_y(int *tetrimino)
{
	int arr[4];
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < 4)
	{
		arr[i] = tetrimino[j];
		i++;
		j += 2;
	}
	while (i > 0)
	{
		j -= 2;
		tetrimino[j] -= move_to_null(arr);
		i--;
	}
}

int		max_x(int *tetrimino)
{
	int i;
	int j;
	int a[4];

	i = 0;
	j = 0;
	while (i < 4)
	{
		a[i] = tetrimino[j];
		i++;
		j += 2;
	}
	i = 0;
	while (i < 3)
	{
		if (a[i] > a[i + 1])
			int_swap(&a[i], &a[i + 1]);
		i++;
	}
	return (a[3]);
}
