/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:42:48 by gverissi          #+#    #+#             */
/*   Updated: 2024/01/08 18:42:11 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pixel(t_img *img, int x, int y, unsigned char color[4])
{
	int	pixel;

	pixel = y * img->line_length + x * (img->bpp / 8);
	color[0] = img->addr[pixel];
	color[1] = img->addr[pixel + 1];
	color[2] = img->addr[pixel + 2];
	color[3] = img->addr[pixel + 3];
}

void	put_pixel(t_img *img, int x, int y, unsigned char color[4])
{
	int	pixel;

	pixel = y * img->line_length + x * (img->bpp / 8);
	img->addr[pixel] = color[0];
	img->addr[pixel + 1] = color[1];
	img->addr[pixel + 2] = color[2];
	img->addr[pixel + 3] = color[3];
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
	int				x;
	int				y;
	unsigned char	color[4];

	y = 0;
	while (y < PIXELS)
	{
		x = 0;
		while (x < PIXELS)
		{
			get_pixel(src_img, x, y, color);
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
