#include "../so_long.h"

void	window_init(void)
{
	window()->mlx_ptr = mlx_init();
	window()->win_ptr = mlx_new_window(window()->mlx_ptr, game()->map_sets.width * PIXELS, game()->map_sets.height * PIXELS, "c runaway");
}