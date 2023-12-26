/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:33:17 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/06 14:00:45 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include <X11/X.h>
# include <X11/keysymdef.h>
# include <sys/time.h>
# define PIXELS 64
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364
# define ESC_KEY			65307

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map {
	int				height;
	int				width;
	int				collectibles;
	int				f_collectibles;
	int				exit;
	int				f_exit;
	int				player;
	int				bots;
	int				movements;
	t_point			player_pos;
}				t_map;

typedef struct s_game
{
	char			**map;
	char			**map_cpy;
	char			**map_f;
	t_map			map_sets;
}	t_game;

typedef struct t_usrwindow{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*floor;
	void	*gvoid;
	void	*collectible;
	void	*exit;
	void	*p;
}	t_window;

void		movement(int x_offset, int y_offset);
void		map(char *argv);
char		**ft_create_map(char **map, int count, char *file);
t_game		*game(void);
t_window	*window(void);
size_t		simp_strlen(char *str);
void		map_checker(void);
void		copy_map(void);
void		free_map_copy(char **map_copy);
int			flood_fill_check(void);
void		ft_exit(const char *error_message);
void		window_init(void);
void		add_images(void);
void		load_images(int i, int j);
void		load_map(void);
int			key_hook(int keycode);
void		add_line(int fd);
int         ft_exit_wrapper(void);
#endif