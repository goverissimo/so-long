NAME = so_long
CC = gcc
CFLAGS = -I/usr/include -Iminilibx -O3

LIBFT = libft/libft.a

SRC = src/main.c src/map_processing.c src/utils.c src/map_checks.c src/map_checks_plus.c src/window.c src/control.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -Lminilibx -lmlx_Linux -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz -o $(NAME)

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
