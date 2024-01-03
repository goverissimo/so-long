# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 12:02:08 by gverissi          #+#    #+#              #
#    Updated: 2023/12/06 12:11:59 by gverissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -I/usr/include -Iminilibx -O3 

LIBFT = libft/libft.a

SRC = src/main.c src/map_processing.c src/utils.c src/map_checks.c src/map_checks_plus.c src/window.c src/control.c src/buff_img.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(MLX):
	make -C ./minilibx

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) $(LIBFT) -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
