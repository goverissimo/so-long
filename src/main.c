#include "so_long.h"
#include <stdio.h>
#include "../libft/libft.h"


t_game 	*game(void)
{
	static t_game	game;

	return (&game);
}
t_window	*window(void)
{
	static t_window	window;

	return (&window);
}

static void print_map_info(void)
{
	printf("Map Information:\n");
	printf("Height: %d\n", game()->map_sets.height);
	printf("Width: %d\n", game()->map_sets.width);
	printf("Collectibles: %d\n", game()->map_sets.collectibles);
	printf("Exit count: %d\n", game()->map_sets.exit);
	printf("Player count: %d\n", game()->map_sets.player);
	printf("Player Position: (X: %d, Y: %d)\n", (game())->map_sets.player_pos.x, (game())->map_sets.player_pos.y);
}


int main(int argc, char **argv)
{
	if(argc == 2)
	{
		map(game(), argv[1]);
		print_map_info();
	}
	window_init();
	mlx_loop(window()->mlx_ptr);
	return 0;
}


