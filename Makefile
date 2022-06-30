# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 21:21:53 by aadnane           #+#    #+#              #
#    Updated: 2022/06/30 13:33:48 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra -Imlx
MLX_FLAGS = -framework OpenGL -framework AppKit -lmlx 
SRCS = so_long.c get_next_line.c parse_map.c utils.c split.c draw_map.c \
check_map.c utils2.c utils3.c
SRCSB = so_long_bonus.c get_next_line.c parse_map_bonus.c utils.c split.c \
draw_map_bonus.c check_map_bonus.c utils2_bonus.c utils3.c utils_bonus_helper.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = so_long
BONUS = so_long_bonus
HEADER = so_long.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $^ $(MLX_FLAGS) -o $@

bonus : $(BONUS)

$(BONUS) : $(OBJSB)
	$(CC) $^ $(MLX_FLAGS) -o $@

%.o  : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJSB)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all
