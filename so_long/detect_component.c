/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_component.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:31:15 by alyazici          #+#    #+#             */
/*   Updated: 2022/08/16 14:28:50 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_buffer(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			count++;
	return (count);
}

void	check_space(t_map *map, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		if (buffer[i++] == ' ')
			exit_game(map, 0);
}

void	control_components(t_map *map)
{
	if (map->collectible_count == 0 || map->player_count != 1 || \
	map->exit_count != 1)
		exit_game(map, 0);
}

void	detect_components(t_map *map, int y, int x)
{
	while (y < map->map_row)
	{
		x = 0;
		while (x < map->map_column)
		{
			if (map->lines[y][x] == 'C')
				map->collectible_count += 1;
			else if (map->lines[y][x] == 'E')
				map->exit_count += 1;
			else if (map->lines[y][x] == 'P')
			{
				map->player_count += 1;
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->lines[y][x] == '0' || \
					map->lines[y][x] == '1')
				;
			else
				exit_game(map, 0);
			x++;
		}
		y++;
	}
	control_components(map);
}
