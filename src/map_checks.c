#include "so_long.h"

static int	is_rectangular(void)
{
	int	i;

	i = 0;
	if (simp_strlen(game()->map[0]) == 0)
	{
		//write invalid
		return (0);
	}
	game()->map_sets.width = simp_strlen(game()->map[0]);
	while (game()->map[i] != NULL)
	{
		if (simp_strlen(game()->map[i]) != game()->map_sets.width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(void)
{
	int	width;
	int	height;
	int	i;

	height = 0;
	while (game()->map[height] != NULL)
		height++;
	if (height == 0)
		return (0);
	width = simp_strlen(game()->map[0]);
	i = 0;
	while (i < width)
	{
		if (game()->map[0][i] != '1' || game()->map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game()->map[i][0] != '1' || game()->map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static	int elements_validation(void)
{
	int i;
	int j;
	char temp;

	i = 0;

	while(i < game()->map_sets.height)
	{
		j = 0;
		while(j < game()->map_sets.width)
		{
			temp = game()->map[i][j];

			if(temp != '0' && temp != '1' && temp != 'C' && temp != 'E' && temp !='P')
				return (0);
			else if(temp == 'P')
			{
				game()->map_sets.player += 1;
				game()->map_sets.player_pos.y = i;

				game()->map_sets.player_pos.x = j;
			}
				game()->map_sets.collectibles += ( temp == 'C');
				game()->map_sets.exit += (temp == 'E');
			j++;
		}
		i++;
	}
	return (1);
}


int	map_checker(void)
{
	//printf("RECTANGULAR :%i\n", is_rectangular());
	//printf("VALIDATION :%i\n", elements_validation());
	//printf("WALLS :%i\n", check_walls());



	if (is_rectangular() && check_walls() && elements_validation())
	{
		if(flood_fill_check())
			return (1);
	}
	return (0);
}
