/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:00:03 by gverissi          #+#    #+#             */
/*   Updated: 2023/11/28 12:06:46 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	key_hook(int keycode)
{
	game()->map_sets.movements += 1;
	if (keycode == KEY_W || keycode == KEY_UP)
		movement(0, -1);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		game()->map_sets.direction = 1;
		movement(1, 0);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		game()->map_sets.direction = -1;
		movement(-1, 0);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		movement(0, 1);
	else if (keycode == ESC_KEY)
	{
		clean();
		ft_exit("Game finished!");
	}
	return (0);
}
static void bot_kill()
{
	ft_printf("YOU DIED\n");
	clean();
	exit (0);
}

void	movement(int x_offset, int y_offset)
{
	int	new_x;
	int	new_y;

	
	new_x = game()->map_sets.player_pos.x + x_offset;
	new_y = game()->map_sets.player_pos.y + y_offset;
	if (new_x < 0 || new_x >= game()->map_sets.width || new_y < 0 \
	|| new_y >= game()->map_sets.height || 
		game()->map[new_y][new_x] == '1')
		return ;
	if (game()->map[new_y][new_x] == '0')
		game()->map_cpy[new_y][new_x] = '1';
	if (game()->map[new_y][new_x] == 'C')
		game()->map_sets.collectibles--;
	if (game()->map[new_y][new_x] == 'B')
		bot_kill();
	if (game()->map[new_y][new_x] == 'E' && game()->map_sets.collectibles == 0)
	{
		printf("%s", "YOU WON");
		clean();
		exit(0);
	}
	game()->map[game()->map_sets.player_pos.y][game()->map_sets.player_pos.x] \
	= '0';
	game()->map_sets.player_pos.x = new_x;
	game()->map_sets.player_pos.y = new_y;
	game()->map[new_y][new_x] = 'P';
	
	load_map();
}

static void movemnt(int x, int y)
{
	printf("%i, %i", game()->map_sets.enemy.y, game()->map_sets.enemy.x);
	if (game()->map_sets.enemy.x + x < 0 || game()->map_sets.enemy.x + x >= game()->map_sets.width ||
        game()->map_sets.enemy.y + y < 0 || game()->map_sets.enemy.y + y >= game()->map_sets.height) {
        return; 
    }

    if (game()->map[game()->map_sets.enemy.y + y][game()->map_sets.enemy.x + x] == 'P')
    {
        bot_kill(); 
		//exit(0);
    }
	else if (game()->map[game()->map_sets.enemy.y + y][game()->map_sets.enemy.x + x] == '1')
	{
		return;
	}
    else if (game()->map[game()->map_sets.enemy.y + y][game()->map_sets.enemy.x + x] == '0')
    {
        game()->map[game()->map_sets.enemy.y][game()->map_sets.enemy.x] = '0';
        game()->map_sets.enemy.y += y;
        game()->map_sets.enemy.x += x;
        game()->map[game()->map_sets.enemy.y][game()->map_sets.enemy.x] = 'B';
    }
}
unsigned int	timer(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int bot_anim(void)
{
int			i;
	int			n;
	static int	j = 0;

	i = 0;
	if (j == 0)
		j = timer();
	if ((timer() - j) < 500)
		return 0;
	j = timer();
	n = rand() % 4;
	while (i < game()->map_sets.bots)
	{
		if (n == 0)
			movemnt(0, -1); 
		if (n == 1)
			movemnt(-1, 0); 
		if (n == 2)
			movemnt(0, 1); 
		if (n == 3)
			movemnt(1, 0); 
		i++;
	}
	return 0;
}