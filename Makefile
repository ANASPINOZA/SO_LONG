# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 21:21:53 by aadnane           #+#    #+#              #
#    Updated: 2022/06/22 20:21:49 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra -Imlx
MLX_FLAGS = -framework OpenGL -framework AppKit -lmlx
SRCS = so_long.c get_next_line.c parse_map.c utils.c split.c draw_map.c check_map.c
OBJS = $(SRCS:.c=.o)
NAME = so_long
HEADER = so_long.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ $(MLX_FLAGS) -o $@
%.o  : %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
