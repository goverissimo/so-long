/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:03 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/01 21:24:43 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	adios(void)
{
	if (window())
	{
		mlx_destroy_image(window()->mlx_ptr, window()->collectible);
		mlx_destroy_image(window()->mlx_ptr, window()->exit);
		mlx_destroy_image(window()->mlx_ptr, window()->wall);
		mlx_destroy_image(window()->mlx_ptr, window()->gvoid);
		mlx_destroy_image(window()->mlx_ptr, window()->floor);
		mlx_destroy_image(window()->mlx_ptr, window()->p);
		mlx_destroy_window(window()->mlx_ptr, window()->win_ptr);
		mlx_destroy_display(window()->mlx_ptr);
		if (game()->map)
			free_map_copy(game()->map);
		if (game()->map_cpy)
			free_map_copy(game()->map_cpy);
		if (game()->map_f)
			free_map_copy(game()->map_f);
		free (window()->mlx_ptr);
		exit (0);
	}
}

int	key_hook(int keycode)
{
	game()->map_sets.movements += 1;
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
		movement(-1, 0);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		movement(0, 1);
	else if (keycode == ESC_KEY)
	{
		ft_printf("Game finished!\n");
		adios();
	}
	return (0);
}


void	movement(int x_offset, int y_offset)
{
	int	new_x;
	int	new_y;

	new_x = game()->map_sets.player_pos.x + x_offset;
	new_y = game()->map_sets.player_pos.y + y_offset;
	if (new_x < 0 || new_x >= game()->map_sets.width || new_y < 0 \
	|| new_y >= game()->map_sets.height || 
		game()->map[new_y][new_x] == '1')
		return ;
	if (game()->map_cpy[new_y][new_x] == '0')
		game()->map_cpy[new_y][new_x] = '1';
	if (game()->map[new_y][new_x] == 'C')
		game()->map_sets.collectibles--;
	if (game()->map[new_y][new_x] == 'E' && game()->map_sets.collectibles == 0)
	{
		ft_printf("%s", "YOU WON\n");
		adios();
	}
	else if (game()->map[new_y][new_x] == 'E' && game()->map_sets.collectibles \
	!= 0)
		return ;
	game()->map[game()->map_sets.player_pos.y][game()->map_sets.player_pos.x] \
	= '0';
	game()->map_sets.player_pos.x = new_x;
	game()->map_sets.player_pos.y = new_y;
	game()->map[new_y][new_x] = 'P';
	load_map();
}
