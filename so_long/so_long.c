/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:35:47 by alyazici          #+#    #+#             */
/*   Updated: 2022/08/16 14:00:05 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map)
{
	map->move_count = 0;
	map->collectible_count = 0;
	map->exit_count = 0;
	map->player_count = 0;
}

void	move(t_map *map, int movey, int movex)
{
	if (map->lines[map->player_y + movey][map->player_x + movex] == '0' || \
			map->lines[map->player_y + movey][map->player_x + movex] == 'C' || \
			map->lines[map->player_y + movey][map->player_x + movex] == 'E')
	{
		if (map->lines[map->player_y + movey][map->player_x + movex] == 'C')
			map->collectible_count--;
		if (map->lines[map->player_y + movey][map->player_x + movex] == 'E')
		{
			if (map->collectible_count == 0)
			{
				ft_printf("%d\n", map->move_count);
				mlx_destroy_window(map->mlx, map->window);
				destroy_game(map, 1);
			}
			else
				return ;
		}
		map->lines[map->player_y][map->player_x] = '0';
		mlx_clear_window(map->mlx, map->window);
		map->lines[map->player_y + movey][map->player_x + movex] = 'P';
		map->player_y += movey;
		map->player_x += movex;
		print_components(map, 0, 0);
	}
}

int	movement(int keycode, t_map *map)
{
	if (keycode == W_KEY)
		move(map, -1, 0);
	else if (keycode == A_KEY)
		move(map, 0, -1);
	else if (keycode == S_KEY)
		move(map, 1, 0);
	else if (keycode == D_KEY)
		move(map, 0, 1);
	else if (keycode == ESC_KEY)
	{
		mlx_destroy_window(map->mlx, map->window);
		destroy_game(map, 1);
	}
	return (0);
}

int	esc_button(t_map *map)
{
	destroy_game(map, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	initialize_map(map);
	read_map(map, av[1]);
	detect_components(map, 0, 0);
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->map_column * 64, \
					map->map_row * 64, "Gaming");
	create_images(map);
	print_components(map, 0, 0);
	mlx_hook(map->window, 2, 1L << 0, &movement, map);
	mlx_hook(map->window, 17, 0, &esc_button, map);
	mlx_loop(map->mlx);
	return (0);
}
