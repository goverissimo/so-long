#include "so_long.h"



int simp_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}

char **copy_map(void)
{
	char **map_cpy;
	int i;

	map_cpy = malloc(sizeof(char *) * game()->map_sets.height);
	if(!map_cpy)
		return 0;
	i = 0;
	while (i < game()->map_sets.height)
	{
		map_cpy[i] = ft_strdup(game()->map[i]);

		if(!map_cpy[i])
		{
			while (i--)
				free(map_cpy[i]);
			free(map_cpy);
			return NULL;
		}
		i++;
	}
	return map_cpy;
}

void free_map_copy(char **map_copy)
{
	int i;

	i = 0;
	while(i < game()->map_sets.height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}