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

static void ft_print_map() {
	if (!game()->map || !game()->map_sets.height) {
		// No map to print or invalid map data
		printf( "Error: No map data found.\n");
		return;
	}

	for (int i = 0; i < game()->map_sets.height; ++i) {
		printf("%s", game()->map[i]);
	}
}


void map(t_game *game, char *argv)
{
	int fd;
	if(!valid_ext(argv))
			return;

	fd = open(argv, O_RDONLY);
	add_line(fd, 0);
	//ft_print_map();
	printf("\n CHECKER: %i", map_checker());
	close(fd);
}