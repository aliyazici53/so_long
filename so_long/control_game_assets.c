/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_game_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:30:34 by alyazici          #+#    #+#             */
/*   Updated: 2022/08/16 14:17:56 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_map *map)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	map->collect_fd = open(COLLECT, O_RDONLY);
	map->exit_fd = open(EXIT, O_RDONLY);
	map->wall_fd = open(WALL, O_RDONLY);
	map->player_fd = open(PLAYER, O_RDONLY);
	if (map->collect_fd < 0 || map->exit_fd < 0 || \
		map->wall_fd < 0 || map->player_fd < 0)
		exit_game(map, 0);
	map->collectible_img = mlx_xpm_file_to_image(map->mlx, COLLECT, &w, &h);
	map->wall_img = mlx_xpm_file_to_image(map->mlx, WALL, &w, &h);
	map->player_img = mlx_xpm_file_to_image(map->mlx, PLAYER, &w, &h);
	map->exit_img = mlx_xpm_file_to_image(map->mlx, EXIT, &w, &h);
}

void	put_image(t_map *map, void *item, int y, int x)
{
	mlx_put_image_to_window(map->mlx, \
							map->window, item, x * 64, y * 64);
}

void	print_components(t_map *map, int y, int x)
{
	if (map->move_count > 0)
		ft_printf("%d\n", map->move_count);
	while (y < map->map_row)
	{
		x = 0;
		while (x < map->map_column)
		{
			if (map->lines[y][x] == '1')
				put_image(map, map->wall_img, y, x);
			else if (map->lines[y][x] == 'P')
				put_image(map, map->player_img, y, x);
			else if (map->lines[y][x] == 'E')
				put_image(map, map->exit_img, y, x);
			else if (map->lines[y][x] == 'C')
				put_image(map, map->collectible_img, y, x);
			else if (map->lines[y][x] == '0')
				;
			else
				destroy_game(map, 0);
			x++;
		}
		y++;
	}
	map->move_count++;
}
