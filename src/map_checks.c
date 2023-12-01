/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:20 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/01 21:17:50 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(void)
{
	int	i;
	int temp;
	int j;

	j = 0;
	temp = 0;
	while(j < game()->map_sets.height)
	{
		if(game()->map[j][0] == '\n')
			return (0);
		j++;
	}
	if (simp_strlen(game()->map[0]) == 0)
		ft_exit("invalid map size");
	i = 0;
	while (game()->map[i] != NULL && game()->map_sets.width == '1')
		i++;
	while (j < i)
	{
		temp = simp_strlen(game()->map[j]);
		if (temp != game()->map_sets.width)
			return (0);
		j++;
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

static int check_temp(char temp, int i, int j)
{
	if(temp != '0' && temp != '1' && temp != 'C' && temp != 'E' && temp != 'P') {
				ft_exit("Unrecognized Character in map");
				return (0);
			}
			else if(temp == 'P')
			{
				game()->map_sets.player += 1;
				game()->map_sets.player_pos.y = i;
				game()->map_sets.player_pos.x = j;
			}
	game()->map_sets.collectibles += ( temp == 'C');
	game()->map_sets.exit += (temp == 'E');
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
			if(check_temp(temp, i, j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if(game()->map_sets.player != 1 || game()->map_sets.exit != 1 || game()->map_sets.collectibles == 0 || game()->map_sets.bots > 1)
		return (0);
	return (1);
}


int	map_checker(void)
{
	copy_map();
	game()->map_sets.width = simp_strlen(game()->map[0]);
	if (is_rectangular() && check_walls() && elements_validation())
	{
		if(flood_fill_check())
			return (1);
	}
	return (0);
}
