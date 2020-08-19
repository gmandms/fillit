/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:17:55 by sbump             #+#    #+#             */
/*   Updated: 2020/02/13 10:16:38 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_square(char *square, int size_square)
{
	int	y;
	int	x;

	y = 0;
	while (y < size_square)
	{
		x = 0;
		while (x < size_square)
		{
			write(1, square++, 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int		max_y(int *tetrimino)
{
	int	i;
	int	a[4];
	int	j;

	i = 0;
	j = 1;
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

int		check_char(char *tetr)
{
	char	**check_str;
	int		i;

	i = 0;
	check_str = malloc(sizeof(char*) * 19);
	check_str = for_check_char(check_str);
	while (i < 19)
	{
		if (ft_strcmp(tetr, check_str[i]) == 0)
		{
			free(check_str);
			return (1);
		}
		i++;
	}
	free(check_str);
	return (0);
}

char	**for_check_char(char **check_str)
{
	check_str[0] = "00010203";
	check_str[1] = "00102030";
	check_str[2] = "00100111";
	check_str[3] = "00010212";
	check_str[4] = "00102001";
	check_str[5] = "00101112";
	check_str[6] = "20011121";
	check_str[7] = "10110212";
	check_str[8] = "00011121";
	check_str[9] = "00100102";
	check_str[10] = "00102021";
	check_str[11] = "10011121";
	check_str[12] = "00011102";
	check_str[13] = "00102011";
	check_str[14] = "10011112";
	check_str[15] = "10200111";
	check_str[16] = "00011112";
	check_str[17] = "00101121";
	check_str[18] = "10011102";
	return (check_str);
}

int		check_coords(int *square, int *t, int size_square)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ((size_square * size_square) * 2))
	{
		if (square[i] == t[0] && square[i + 1] == t[1] && j == 0)
			j++;
		if (square[i] == t[2] && square[i + 1] == t[3] && j == 1)
			j++;
		if (square[i] == t[4] && square[i + 1] == t[5] && j == 2)
			j++;
		if (square[i] == t[6] && square[i + 1] == t[7] && j == 3)
			return (1);
		i += 2;
	}
	return (0);
}
