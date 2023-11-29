/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:01:13 by gverissi          #+#    #+#             */
/*   Updated: 2023/11/29 15:34:46 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void display_movement_count()
{
    char *move_str;
    move_str = ft_itoa(game()->map_sets.movements); 
    mlx_string_put(window()->mlx_ptr, window()->win_ptr, 10, 20, 0xFFFFFF, move_str);
	free(move_str);
}

void	window_init(void)
{
	window()->mlx_ptr = mlx_init();
	window()->win_ptr = mlx_new_window((window())->mlx_ptr, (game())->map_sets.width * PIXELS, (game())->map_sets.height * PIXELS, "Pacman");
	add_images();
	load_map();
}

void	add_images(void)
{
	int	i;
	i = PIXELS;
	(window()->p[0]) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/player.xpm", &i, &i);
	(window()->p[1]) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/mc.xpm", &i, &i);
	(window()->collectible) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/dot_big.xpm", &i, &i);
	(window()->wall) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/wall.xpm", &i, &i);
	(window()->exit) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/exit.xpm", &i, &i);
	(window()->rp[0]) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/playerr.xpm", &i, &i);
	(window()->rp[1]) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/mcr.xpm", &i, &i);
	(window()->gvoid) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/black.xpm", &i, &i);
	(window()->floor) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/dot_small.xpm", &i, &i);
	(window()->enemy1) = mlx_xpm_file_to_image(window()->mlx_ptr, "./sprites/eb1.xpm", &i, &i);

}

void	load_images(int i, int j)
{
	game()->map_sets.direction = 0;
	if(game()->map_sets.frame == 1)
		game()->map_sets.frame = 0;
	else if(game()->map_sets.frame == 0)
		game()->map_sets.frame = 1;
	if (game()->map_sets.direction == 1 || game()->map_sets.direction == 0)
		window()->player = window()->p[game()->map_sets.frame];
	else if (game()->map_sets.direction == -1)
		window()->player = window()->rp[game()->map_sets.frame];
	if(game()->map[i][j] == '1')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->wall, j* 64, i* 64);
	else if(game()->map[i][j] == 'C')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->collectible, j* 64, i* 64);
	else if(game()->map[i][j] == 'P')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->player, j* 64, i* 64);
	else if(game()->map[i][j] == 'B')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->enemy1, j* 64, i* 64);
	else if(game()->map[i][j] == 'E' && game()->map_sets.collectibles == 0)
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->exit, j* 64, i* 64);
	else if(game()->map[i][j] == '0' && game()->map_cpy[i][j] == '0')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->floor, j* 64, i* 64);
	else if(game()->map[i][j] == '0' && game()->map_cpy[i][j] == '1')
		mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, window()->gvoid, j* 64, i* 64);
	display_movement_count();
}

void	load_map(void)
{
	mlx_clear_window(window()->mlx_ptr, window()->win_ptr);
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


