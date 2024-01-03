/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:58 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/04 14:32:51 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	simp_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '0' && str[i] != '\n' && str[i])
		i++;
	return (i);
}

void	copy_map(void)
{
	char	**map_cpy;
	int		i;
	int		j;

	j = 0;
	game()->map_f = malloc(sizeof(char *) * (game()->map_sets.height + 1));
	game()->map_cpy = malloc(sizeof(char *) * (game()->map_sets.height + 1));
	if (!game()->map_cpy || !game()->map_f)
		return ;
	i = 0;
	while (i < game()->map_sets.height)
	{
		game()->map_cpy[i] = ft_strdup(game()->map[i]);
		game()->map_f[i] = ft_strdup(game()->map[i]);
		i++;
	}
	game()->map_cpy[i] = NULL;
	game()->map_f[i] = NULL;
}

void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
	{
		free (map_copy[i++]);
	}
	free (map_copy);
}
