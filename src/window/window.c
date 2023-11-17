#include "../so_long.h"

void	window_init(void)
{
	window()->mlx_ptr = mlx_init();
	window()->win_ptr = mlx_new_window((window())->mlx_ptr, (game())->map_sets.width * PIXELS, (game())->map_sets.height * PIXELS, "c runaway");
	add_images();
	load_map();

}
void	add_images(void)
{
	int i = 64;
	window()->player[0] = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/player/stop.xpm", &i, &i);
	(window()->floor) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/wall.xpm", &i, &i);
	(window()->collectible) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/coin.xpm", &i, &i);
	(window()->wall) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/wall.xpm", &i, &i);
	(window()->exit) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/wall.xpm", &i, &i);

}

void	load_images(int i, int j)
{

	if(game()->map[i][j] == '1')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->wall, j* 64, i* 64);
	else if(game()->map[i][j] == '0')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->floor, j* 64, i* 64);
	else if(game()->map[i][j] == 'C')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->collectible, j* 64, i* 64);
	else if(game()->map[i][j] == 'P')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->player[0], j* 64, i* 64);

}
void	load_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < game()->map_sets.height)
	{
		j = 0;
		while (j < game()->map_sets.width)
		{
			load_images(i, j);
			j++;
		}
		i++;
	}
}
