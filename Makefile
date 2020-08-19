# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbump <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/27 18:13:34 by sbump             #+#    #+#              #
#    Updated: 2020/02/15 11:27:56 by sbump            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./move_coords.c ./check_coords.c ./record_tetrimino.c ./source.c\
./print.c ./read.c ./check_copy.c ./square_copy.c ./get_next_line.c ./main.c

HDR = ./get_next_line.h ./fillit.h

LIBFT = libft/

all: $(NAME)

lib_compile:
	make -C $(LIBFT)

$(NAME): lib_compile
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIBFT)libft.a

clean:
	make -C $(LIBFT) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
