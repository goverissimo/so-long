#include "so_long.h"
#include <stdio.h>
#include "../libft/libft.h"


t_game 	*game(void)
{
	static t_game	game;

	return (&game);
}

int main(int argc, char **argv)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game) {
		perror("Failed to allocate memory for game");
		return 1;
	}

	//printf("%s", argv[1]);
	map(game, argv[1]);
	//printf("%i", game->map_sets.rows);
	return 0;
}


