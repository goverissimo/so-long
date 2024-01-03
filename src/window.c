/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:01:13 by gverissi          #+#    #+#             */
/*   Updated: 2024/01/03 17:46:48 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	display_movement_count(void)
{
	char	*move_str;

	move_str = ft_itoa (game()->map_sets.movements); 
	mlx_string_put (window()->mlx_ptr, window()->win_ptr, 10, 20, 0xFFFFFF, \
	move_str);
	free (move_str);
}

void	window_init(void)
{
	window()->mlx_ptr = mlx_init();
	(window()->win_ptr) = mlx_new_window(window()->mlx_ptr, \
	game()->map_sets.width * 64, game()->map_sets.height * 64, "Pacman");
	add_images();
	load_map();
}

void	add_images(void)
{
	int	i;

	i = PIXELS;
	(window()->p) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"./sprites/player.xpm", &i, &i);
	(window()->collectible) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"./sprites/dot_big.xpm", &i, &i);
	(window()->wall) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"./sprites/wall.xpm", &i, &i);
	(window()->exit) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"./sprites/exit.xpm", &i, &i);
	(window()->gvoid) = mlx_xpm_file_to_image(window()->mlx_ptr, \
	"./sprites/black.xpm", &i, &i);
}

void	*choose_image(char map_char, char map_cpy_char)
{
	if (map_char == '1')
		return (window()->wall);
	if (map_char == 'C')
		return (window()->collectible);
	if (map_cpy_char == 'E')
	{
		if (game()->map_sets.collectibles == 0)
			return (window()->exit);
		else
			return (window()->gvoid);
	}
	return (window()->gvoid);
}

void	load_map(void)
{
	t_img	buffer;
	int		i;
	int		j;

	buffer = init_img(window()->mlx_ptr, game()->map_sets.width * \
	PIXELS, game()->map_sets.height * PIXELS);
	i = 0;
	while (i < game()->map_sets.height)
	{
		j = -1;
		while (++j < game()->map_sets.width)
			load_images(&buffer, i, j);
		i++;
	}
	mlx_put_image_to_window(window()->mlx_ptr, window()->win_ptr, \
	buffer.img, 0, 0);
	display_movement_count();
	mlx_destroy_image(window()->mlx_ptr, buffer.img);
}
