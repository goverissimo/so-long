/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:58 by gverissi          #+#    #+#             */
/*   Updated: 2023/11/29 16:04:15 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t simp_strlen(char *str)
{
	size_t i;
	i = 0;
	if(!str)
		return 0;
	while (str[i] != '0' && str[i] != '\n' && str[i])
		i++;
	return (i);
}

void copy_map(void)
{
	char **map_cpy;
	int i;

	map_cpy = ft_calloc(sizeof(char *),(game()->map_sets.height + 1));
	if(!map_cpy)
		return ;
	i = 0;
	while (i < game()->map_sets.height)
	{
		map_cpy[i] = ft_strdup(game()->map[i]);
		i++;
	}
	game()->map_cpy = map_cpy;
	game()->map_f = map_cpy;
	//free(map_cpy);
}

void free_map_copy(char **map_copy)
{
	int i;

	i = 0;
	while(map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	map_copy = NULL;
}

void clean(void)
{
	int i;
	i = 0;
	if(window()->collectible)
		mlx_destroy_image(window()->mlx_ptr, window()->collectible);
	if(window()->exit)
		mlx_destroy_image(window()->mlx_ptr, window()->exit);
	if(window()->enemy1)
		mlx_destroy_image(window()->mlx_ptr, window()->enemy1);
	if(window()->wall)
		mlx_destroy_image(window()->mlx_ptr, window()->wall);
	if(window()->gvoid)
		mlx_destroy_image(window()->mlx_ptr, window()->gvoid);
	if(window()->floor)
		mlx_destroy_image(window()->mlx_ptr, window()->floor);
	// if(window()->player)
	// 	mlx_destroy_image(window()->mlx_ptr, window()->player);
	while (i < 2)
	{
		mlx_destroy_image(window()->mlx_ptr, window()->p[i]);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(window()->mlx_ptr, window()->rp[i]);
		i++;
	}
	mlx_destroy_window(window()->mlx_ptr, window()->win_ptr);
	mlx_destroy_display(window()->mlx_ptr);
	free(window()->mlx_ptr);
		
}
