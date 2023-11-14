#ifndef SO_LONG
# define SO_LONG
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {

	int				height;
	int				width;
	int				collectibles;
	int				exit;
	int				player;
	t_point			player_pos;
}				t_map;


typedef struct	s_game
{
	char			**map;
	t_map		map_sets;

}	t_game;

typedef  struct program_settings
{
	char *map_file;
} p_settings;

void map(t_game *game, char *argv);
char	**ft_create_map(char **map, int count, char *file);
t_game 	*game(void);
int simp_strlen(char *str);
int map_checker(void);




#endif