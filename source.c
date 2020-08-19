/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:24:20 by sbump             #+#    #+#             */
/*   Updated: 2020/02/10 20:25:43 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	int_swap(int *n1, int *n2)
{
	int tmp_n;

	tmp_n = *n1;
	*n1 = *n2;
	*n2 = tmp_n;
}

int		**make_arr(int size1, int size2)
{
	int i;
	int j;
	int **arr;

	arr = malloc(sizeof(int*) * size1);
	i = 0;
	while (i < size1)
	{
		j = 0;
		arr[i] = malloc(sizeof(int) * size2);
		while (j < size2)
		{
			arr[i][j] = j;
			j++;
		}
		i++;
	}
	return (arr);
}

int		write_square(int *tetrimino, int x, int y)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (tetrimino[i] == x && tetrimino[i + 1] == y)
			return (1);
		i += 2;
	}
	return (0);
}

void	record_square(char *s, int *t, char l, int size_square)
{
	int x;
	int y;

	y = 0;
	while (y < size_square)
	{
		x = 0;
		while (x < size_square)
		{
			if (write_square(t, x, y) == 1)
				*s = l;
			x++;
			s++;
		}
		y++;
	}
}
