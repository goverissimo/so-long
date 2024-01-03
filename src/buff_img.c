/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:42:48 by gverissi          #+#    #+#             */
/*   Updated: 2024/01/03 17:46:12 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

uint32_t	get_pixel(t_img *img, int x, int y)
{
	return (*(uint32_t *)(img->addr + (y * img->line_length + x * \
	(img->bpp / 8))));
}

void	put_pixel(t_img *img, int x, int y, uint32_t color)
{
	*(uint32_t *)(img->addr + (y * img->line_length + x * \
	(img->bpp / 8))) = color;
}

t_img	init_img(void *mlx_ptr, int width, int height)
{
	t_img	img;

	img.img = mlx_new_image(mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img, \
	&img.bpp, \
	&img.line_length, \
	&img.endian);
	return (img);
}

void	draw_image_to_buffer(t_img *src_img, t_img *buffer, \
int start_x, int start_y)
{
	int			x;
	int			y;
	uint32_t	color;

	y = 0;
	while (y < PIXELS)
	{
		x = 0;
		while (x < PIXELS)
		{
			color = get_pixel(src_img, x, y);
			put_pixel(buffer, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

void	load_images(t_img *buffer, int i, int j)
{
	t_img	src_img;

	src_img.img = choose_image(game()->map[i][j], game()->map_cpy[i][j]);
	src_img.addr = mlx_get_data_addr(src_img.img, &src_img.bpp, \
	&src_img.line_length, &src_img.endian);
	draw_image_to_buffer(&src_img, buffer, j * PIXELS, i * PIXELS);
	if (game()->map[i][j] == 'P')
	{
		src_img.img = window()->p;
		src_img.addr = mlx_get_data_addr(src_img.img, &src_img.bpp, \
		&src_img.line_length, &src_img.endian);
		draw_image_to_buffer(&src_img, buffer, j * PIXELS, i * PIXELS);
	}
}
