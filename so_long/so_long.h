/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyazici <alyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:37:20 by alyazici          #+#    #+#             */
/*   Updated: 2022/08/16 14:28:56 by alyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "mlx/mlx.h"

typedef struct s_map
{
	void	*wall_img;
	void	*collectible_img;
	void	*player_img;
	void	*exit_img;
	void	*mlx;
	void	*window;
	char	**lines;
	char	*map;	
	int		map_column;
	int		map_row;
	int		player_x;
	int		player_y;
	int		move_count;
	int		collectible_count;
	int		exit_count;
	int		player_count;
	int		collect_fd;
	int		exit_fd;
	int		player_fd;
	int		wall_fd;
}				t_map;

//free_and_exit
void	free_map(t_map *map);
void	exit_game(t_map *map, int gameover);
void	destroy_game(t_map *map, int gameover);
//detect_component
void	detect_components(t_map *map, int y, int x);
void	control_components(t_map *map);
int		check_buffer(char *buffer);
void	check_space(t_map *map, char *buffer);
//read_map
void	extension(t_map *map, char *berfile);
void	read_map(t_map *map, char *berfile);
void	check_all_map(t_map *map, char *buffer);
void	check_walls(t_map *map);
void	check_top_bottom(t_map *map, int row);
//control_game_asset
void	create_images(t_map *map);
void	put_image(t_map *map, void *item, int y, int x);
void	print_components(t_map *map, int y, int x);

//utils
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd, int *count);
int		ft_putstr_fd(char *s, int fd);

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd, t_map *map);
int		isnlchar(char *buffer);
char	*next_line(char	*buffer);
char	*update_buffer(char	*buffer);

# define PLAYER "images/player.xpm"
# define COLLECT "images/collect.xpm"
# define WALL "images/wall.xpm"
# define EXIT "images/exit.xpm"

# define W_KEY 13
# define A_KEY 0 
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

#endif