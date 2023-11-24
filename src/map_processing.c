#include "so_long.h"

static int valid_ext(char *map_file)
{
	if(ft_strncmp(".ber", &map_file[ft_strlen(map_file)-4],4) == 0)
		return 1;
	return 0;
}

void	add_line(int fd, int height)
{
	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	if(line)
		add_line(fd, height + 1);
	else if(height > 0)
	{
		game()->map = malloc(sizeof(char *) * (height + 1));
		game()->map_sets.height = height;
		//printf("%i", height);
	}
	if(game()->map)
		game()->map[height] = line;

}

void map(char *argv)
{
	int fd;
	if(!valid_ext(argv)) {
		write(1, "Add a valid file!", 17);
		exit(0);
	}
		fd = open(argv, O_RDONLY);
		add_line(fd, 0);
		game()->map_cpy = copy_map();
		close(fd);

}