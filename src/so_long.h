/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:33:17 by gverissi          #+#    #+#             */
/*   Updated: 2024/01/03 17:48:13 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"
# include <stdint.h>
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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

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
t_img		init_img(void *mlx_ptr, int width, int height);
uint32_t	get_pixel(t_img *img, int x, int y);
void		put_pixel(t_img *img, int x, int y, uint32_t color);
t_img		init_img(void *mlx_ptr, int width, int height);
void		load_images(t_img *buffer, int i, int j);
void		load_map(void);
int			key_hook(int keycode);
void		add_line(int fd);
int			ft_exit_wrapper(void);
void		*choose_image(char map_char, char map_cpy_char);
#endif