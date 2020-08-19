/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_tetrimino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:23:35 by sbump             #+#    #+#             */
/*   Updated: 2020/02/10 20:23:37 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_tetrimino(char *tetriminoline, int *tetrimino)
{
	int i;
	int x;
	int y;
	int o;

	y = 0;
	i = 0;
	o = 0;
	tetrimino[o] = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetriminoline[i] == '#')
			{
				tetrimino[o] = x - null_x(tetriminoline);
				tetrimino[o + 1] = y - null_y(tetriminoline);
				o += 2;
			}
			i++;
			x++;
		}
		y++;
	}
}

int		null_y(char *tetriminoline)
{
	int i;
	int arr[4];
	int x;
	int y;
	int o;

	y = 0;
	o = 0;
	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetriminoline[i] == '#')
			{
				arr[o] = y;
				o++;
			}
			x++;
			i++;
		}
		y++;
	}
	return (move_to_null(arr));
}

int		null_x(char *tetriminoline)
{
	int i;
	int arr[4];
	int x;
	int y;
	int o;

	y = 0;
	o = 0;
	i = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetriminoline[i] == '#')
			{
				arr[o] = x;
				o++;
			}
			x++;
			i++;
		}
		y++;
	}
	return (move_to_null(arr));
}

int		move_to_null(int *arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (arr[i] > arr[i + 1])
		{
			int_swap(&arr[i], &arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return (arr[0]);
}

void	tetrimino_while(int *tetrimino, int i)
{
	while (i < 8)
	{
		tetrimino[i] += 1;
		i += 2;
	}
}
