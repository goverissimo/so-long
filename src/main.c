/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:46 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/01 20:02:30 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

t_window	*window(void)
{
	static t_window	window;

	return (&window);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		game()->map_sets.direction = 1;
		game()->map_sets.frame = 1;
		map(argv[1]);
		map_checker();
		window_init();
		mlx_key_hook(window()->win_ptr, key_hook, window());
		mlx_loop(window()->mlx_ptr);
	}
	else
		ft_exit("Please enter 2 arguments");
	return (0);
}
