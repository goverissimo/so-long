/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:47 by gverissi          #+#    #+#             */
/*   Updated: 2023/11/29 15:55:07 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static	int	valid_ext(char *map_file)
{
	if (ft_strncmp (".ber", &map_file[ft_strlen(map_file)-4], 4) == 0)
		return (1);
	return (0);
}

void add_line(int fd)
{
    char *line;
    int height = 0;

    // Temporary array to store lines
    char **temp_lines = ft_calloc(1000, sizeof(char *));  // MAX_LINES is an estimated upper limit

    while ((line = get_next_line(fd)) != NULL)
    {
		
        temp_lines[height++] = line;
		if(temp_lines[height-1][0] == '\n')
			ft_exit("remove newlines before runnig the project") ;
    }

    // Allocate memory for the exact number of lines read
    game()->map = malloc(sizeof(char *) * (height + 1));  // +1 for null-termination

    // Copy lines to game()->map and free temporary storage
    for (int i = 0; i < height; i++)
    {
        game()->map[i] = temp_lines[i];
    }
    game()->map[height] = NULL;  // Null-terminate the array
	game()->map_sets.height = height;
    free(temp_lines);  // Free temporary line storage
}



void	map(char *argv)
{
	int	fd;

	if (!valid_ext(argv))
	{
		printf("add a valid file");
		exit(0);
	}
	
	fd = open(argv, O_RDONLY);

	add_line(fd);

	close(fd);

}
