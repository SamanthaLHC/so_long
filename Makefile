# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sam <sam@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 14:13:22 by sle-huec          #+#    #+#              #
#    Updated: 2022/03/18 18:51:43 by sam              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c \
		window.c \
		maps.c \
		get_next_line.c \
		get_next_line_utils.c
		
OBJ = $(SRCS:%.c=%.o)

CC = cc 

MLX = mlx/libmlx_Linux.a 

$(NAME): $(OBJ) $(MLX)
	$(CC) $(OBJ) -g3 -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -g3 -DBUFFER_SIZE=1 -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@

$(MLX):
	make -C ./mlx 

clean: 
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)

all: $(NAME) 
	
re: fclean all
	
.PHONY: clean fclean all re 