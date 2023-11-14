#include "so_long.h"
#include <stdio.h>
#include "../libft/libft.h"


t_game 	*game(void)
{
	static t_game	game;

	return (&game);
}

static void print_map_info(const t_map *map)
{
	if (map == NULL) {
		printf("Map data is null.\n");
		return;
	}

	printf("Map Information:\n");
	printf("Height: %d\n", map->height);
	printf("Width: %d\n", map->width);
	printf("Collectibles: %d\n", map->collectibles);
	printf("Exit count: %d\n", map->exit);
	printf("Player count: %d\n", map->player);
	printf("Player Position: (X: %d, Y: %d)\n", map->player_pos.x, map->player_pos.y);
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
	print_map_info(game().map_sets);
	return 0;
}


