/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:46 by gverissi          #+#    #+#             */
/*   Updated: 2023/11/29 15:48:56 by gverissi         ###   ########.fr       */
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
		//ft_memset(game(),0,sizeof(game()));
		map(argv[1]);

		map_checker();
		
		printf("height:%i, width:%i, player:%i", game()->map_sets.height, game()->map_sets.width, game()->map_sets.player);
		
		window_init();
		mlx_key_hook(window()->win_ptr, key_hook, NULL);
		mlx_loop_hook(window()->mlx_ptr, bot_anim, NULL);
		mlx_loop(window()->mlx_ptr);
		clean();
	
		free_map_copy(game()->map);
		free_map_copy(game()->map_cpy);
		//free_map_copy(game()->map_f);
		
	}
	else
		ft_exit("Please enter 2 arguments");
	return (0);
}
