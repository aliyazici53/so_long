/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:47:48 by alyazici          #+#    #+#             */
/*   Updated: 2022/04/29 17:47:49 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*first_line(int fd, char *buffer, t_map *map)
{
	char	*line;
	int		byteread;

	byteread = 1;
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (0);
	while (!isnlchar(buffer) && byteread != 0)
	{
		byteread = read(fd, line, BUFFER_SIZE);
		if (byteread == -1)
		{
			free(buffer);
			free(line);
			free(map);
		}
		line[byteread] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd, t_map *map)
{
	char		*line;
	static char	*buffer;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (0);
	buffer = first_line(fd, buffer, map);
	if (!buffer)
		return (0);
	line = next_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
