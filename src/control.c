#include "so_long.h"
#include <X11/X.h>
#include <X11/keysymdef.h>

int key_hook(int keycode)
{
    if (keycode == KEY_W || keycode == KEY_UP)
		movement(0, -1);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		game()->map_sets.direction = 1;
		movement(1, 0);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		game()->map_sets.direction = -1;
		movement(-1,0);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		movement(0,1);
    return 0;
}
void movement(int x_offset, int y_offset) {
	int new_x;
	int new_y;

	new_x = game()->map_sets.player_pos.x + x_offset;
	new_y = game()->map_sets.player_pos.y + y_offset;

	if (new_x < 0 || new_x >= game()->map_sets.width || new_y < 0 || new_y >= game()->map_sets.height ||
		game()->map[new_y][new_x] == '1')
		return;
	if (game()->map[new_y][new_x] == '0')
		game()->map_cpy[new_y][new_x] = '1';
	if (game()->map[new_y][new_x] == 'C')
	{
		game()->map_sets.collectibles--;
	}
	if (game()->map[new_y][new_x] == 'E' && game()->map_sets.collectibles == 0)
	{
		clean();
		exit(0);
	}
	game()->map[game()->map_sets.player_pos.y][game()->map_sets.player_pos.x] = '0'; // Set the old position to empty
	//mlx_destroy_image(window()->mlx_ptr, window()->f)
	game()->map_sets.player_pos.x = new_x;
	game()->map_sets.player_pos.y = new_y;
	game()->map[new_y][new_x] = 'P';

	load_map();
}
