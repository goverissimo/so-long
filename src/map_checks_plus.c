#include "so_long.h"

static	void	flood_fill(int x, int y, char **map)
{
	if (x < 0 || y < 0 || x >= game()->map_sets.width || \
	y >= game()->map_sets.height || map[y][x] == '1')
		return ;
	game()->map_sets.f_collectibles += (map[y][x] == 'C');
	game()->map_sets.f_exit += (map[y][x] == 'E');
	map[y][x] = '1';
	flood_fill(x + 1, y, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x, y - 1, map);
}

int	flood_fill_check(void)
{
	char	**map_cpy;

	game()->map_sets.f_exit = 0;
	map_cpy = copy_map();
	flood_fill(game()->map_sets.player_pos.x, game()->map_sets.player_pos.y, map_cpy);
	if (game()->map_sets.f_exit == 0)
	{
		ft_exit("Exit not accessible");
		return (0);
	}
	else if (game()->map_sets.f_collectibles != game()->map_sets.collectibles)
	{
		ft_exit("COLLETIBLES NOT ACCESSIBLE");
		return (0);
	}
	free_map_copy(map_cpy);
	return (1);
}

void ft_exit(const char *error_message)
{
	//write(1, error_message, ft_strlen(error_message));
	//write(1, "\n", 1);
	exit(0);
}
