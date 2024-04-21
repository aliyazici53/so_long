/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:32:54 by alyazici          #+#    #+#             */
/*   Updated: 2022/08/16 14:47:04 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extension(t_map *map, char *berfile)
{
	int	i;

	if (!berfile)
	{
		ft_printf("Error\n");
		free(map);
		exit(1);
	}
	i = ft_strlen(berfile);
	if (berfile[i - 1] != 'r' || berfile[i - 2] != 'e' || \
		berfile[i - 3] != 'b' || berfile[i - 4] != '.')
	{
		ft_printf("Error\n");
		free(map);
		exit(1);
	}
}

void	check_top_bottom(t_map *map, int row)
{
	int	i;

	i = 0;
	while (i < map->map_column)
	{
		if (map->lines[row][i] != '1')
			exit_game(map, 0);
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	check_top_bottom(map, 0);
	check_top_bottom(map, map->map_row - 1);
	i = 1;
	while (i < map->map_row - 1)
	{
		if (map->lines[i][0] != '1' || \
			map->lines[i][map->map_column - 1] != '1')
			exit_game(map, 0);
		i++;
	}
	i = 0;
	while (map->lines[i])
		if (ft_strlen(map->lines[0]) != ft_strlen(map->lines[i++]))
			exit_game(map, 0);
}

void	check_all_map(t_map *map, char *buffer)
{
	int	i;
	int	row;
	int	column;
	int	nl_count;

	nl_count = check_buffer(buffer);
	row = 0;
	i = 0;
	while (map->lines[i])
		i++;
	row = i;
	i = 0;
	while (map->lines[0][i] != '\n' && map->lines[0][i] != '\0')
		i++;
	column = i;
	if (row - 1 != nl_count)
		exit_game(map, 0);
	map->map_column = column;
	map->map_row = row;
	check_space(map, buffer);
	check_walls(map);
}

void	read_map(t_map *map, char *berfile)
{
	char	*buffer;
	char	*line;
	int		fd;

	extension(map, berfile);
	fd = open(berfile, O_RDONLY);
	if (fd < 0)
		free_map(map);
	line = get_next_line(fd, map);
	if (!line)
		free_map(map);
	buffer = ft_strdup("");
	while (1)
	{
		buffer = ft_strjoin(buffer, line);
		free(line);
		line = get_next_line(fd, map);
		if (!line)
			break ;
	}
	map->lines = ft_split(buffer, '\n');
	check_all_map(map, buffer);
	free(buffer);
}
