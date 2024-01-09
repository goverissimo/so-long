/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:47 by gverissi          #+#    #+#             */
/*   Updated: 2024/01/08 17:54:11 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	valid_ext(char *map_file)
{
	if (ft_strncmp (".ber", &map_file[ft_strlen(map_file)-4], 4) == 0)
		return (1);
	return (0);
}

static	void	free_temp_lines(char **lines, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(lines[i]);
	free(lines);
	ft_exit ("remove newlines before running the project");
}

void	add_line(int fd)
{
	char	*line;
	int		height;
	char	**temp_lines;
	int		i;

	i = -1;
	height = 0;
	temp_lines = ft_calloc(1000, sizeof(char *));
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp_lines[height++] = line;
		if (temp_lines[height - 1][0] == '\n')
			free_temp_lines(temp_lines, height);
		line = get_next_line(fd);
	}
	game()->map = malloc(sizeof(char *) * (height + 1)); 
	while (++i < height)
		game()->map[i] = temp_lines[i];
	game()->map[height] = NULL;
	game()->map_sets.height = height;
	free(temp_lines);
	free(line);
}

void	map(char *argv)
{
	int	fd;

	if (!valid_ext(argv))
	{
		ft_exit("add a valid file");
		exit(0);
	}
	fd = open(argv, O_RDONLY);
	add_line(fd);
	close (fd);
}
