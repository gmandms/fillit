/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbump <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:31:15 by sbump             #+#    #+#             */
/*   Updated: 2020/02/13 07:10:18 by sbump            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"

void	record_tetriminoline(char **tetriminoline, int fd);
int		file_read(int fd, int *size);
int		check(int size, char **tetriminoline);
int		check_tetriminoline(char *tetriminoline);
void	int_swap(int *n1, int *n2);
int		**make_arr(int size1, int size2);
int		write_square(int *tetrimino, int x, int y);
void	record_square(char *s, int *t, char l, int size_square);
void	write_tetrimino(char *tetriminoline, int *tetrimino);
int		null_y(char *tetriminoline);
int		null_x(char *tetriminoline);
int		move_to_null(int *arr);
void	tetrimino_while(int *tetrimino, int i);
void	paste_to_square(int **tetrimino, int size);
int		*make_square(int size);
void	paste(int *square, int **tetrimino, int size, int size_square);
char	*char_square(int **tetrimino, int size, int square_size);
char	*record(char *square, int **tetrimino, int size, int size_square);
int		max_x(int *tetrimino);
int		max_y(int *tetrimino);
int		move_coords(int *tetrimino, int size_square);
void	nullified_x(int *tetrimino);
void	nullified_y(int *tetrimino);
int		if_move_coords(int *tetrimino, int size_square);
int		min_map(int size);
int		compare_all_coords(int **tetrimino, int i, int size_quare);
int		compare_coords(int *t1, int *t2);
void	print_square(char *square, int size_square);
int		paste_tetrimino(int *s, int **tetrimino, int size, int size_square);
int		for_paste_tetrimino(int **tetrimino, int i, int size_square);
void	for_record_tetriminoline(char **tetriminoline, char *one, int i);
int		check_char(char *tetr);
int		ft_for_check_tetrimino(int *tetrimino);
int		check_tetrimino(int **tetrimino, int size);
char	*ft_strjoin_null(char *one, char *line);
char	**make_check(char **check, int size);
char	**for_check_char(char **check_str);
int		check_coords(int *square, int *t, int size_square);
char	**ft_for_main(int size, char *argv);
int		check_main(int argc, char *argv);
int		for_file_read(int *size, char *line, int n);

#endif
