/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:36 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/06 14:00:36 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	flood_fill(int x, int y, char **map)
{
	if (x < 0 || y < 0 || x >= game()->map_sets.width || \
	y >= game()->map_sets.height || map[y][x] == '1' || map[y][x] == 'F')
		return ;
	game()->map_sets.f_collectibles += (map[y][x] == 'C');
	game()->map_sets.f_exit += (map[y][x] == 'E');
	map[y][x] = 'F';
	flood_fill(x + 1, y, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x, y - 1, map);
}

int	flood_fill_check(void)
{
	flood_fill(game()->map_sets.player_pos.x, game()->map_sets.player_pos.y, \
	game()->map_f);
	if (game()->map_sets.f_exit == 0)
	{
		ft_exit ("Exit not accessible");
		return (0);
	}
	else if (game()->map_sets.f_collectibles != game()->map_sets.collectibles)
	{
		ft_exit ("COLLETIBLES NOT ACCESSIBLE");
		return (0);
	}
	return (1);
}

void	ft_exit(const char *error_message)
{
	ft_printf("ERROR:%s \n", error_message);
	if (game()->map)
		free_map_copy(game()->map);
	if (game()->map_cpy)
		free_map_copy(game()->map_cpy);
	if (game()->map_f)
		free_map_copy(game()->map_f);
	exit (0);
}

int	ft_exit_wrapper(void)
{
	ft_printf("X pressed");
	cleaner();
	return (0);
}
