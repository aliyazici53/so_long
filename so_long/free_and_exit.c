/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:32:18 by alyazici          #+#    #+#             */
/*   Updated: 2022/08/16 14:48:20 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	ft_printf("Error\n");
	free(map);
	exit(1);
}

void	exit_game(t_map *map, int gameover)
{
	int	i;

	i = 0;
	if (!gameover)
		ft_printf("Error\n");
	while (map->lines[i])
		free(map->lines[i++]);
	free(map->lines);
	free(map);
	exit(1);
}

void	destroy_game(t_map *map, int gameover)
{
	mlx_destroy_image(map->mlx, map->collectible_img);
	mlx_destroy_image(map->mlx, map->exit_img);
	mlx_destroy_image(map->mlx, map->wall_img);
	mlx_destroy_image(map->mlx, map->player_img);
	if (!gameover)
		ft_printf("Error\n");
	exit_game(map, 1);
}
