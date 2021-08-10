/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/10 18:26:51 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx_mms_20200219/mlx.h"

# define ERROR_MSG "Error\n"
# define ASSET_HEIGHT 100
# define ASSET_WIDTH 100

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		window_height;
	int		window_width;
}				t_image;

typedef struct	s_parse_info {
	int 	exit_exists;
	int 	collect_exists;
	int 	player_exists;
}				t_parse_info;

typedef struct	s_map {
	char		**map;
	int			max_x;
	int			max_y;
	int			player_x;
	int			player_y;
}				t_map;

typedef struct 	s_game {
	t_map 		map;	
	void		*mlx_instance;
	void		*mlx_window;
	t_image		*image_to_write;
	int			**asset_floor;
	int			**asset_wall;
	int			**asset_player;
	int			**asset_coll;
	int			**asset_exit;
}				t_game;

/* utils */
int	gets_map_fd(char *filename);
int	free_map_and_make_error(t_map *map_struct);
void	get_player_position(t_map *map_struct, char *line);

/* parser */
int parser(t_game *game, char *filename, t_map *map_struct);
void	load_texture(t_game *game, int ***pointer, char *path_to_file);

/* window */
int	window(t_game *game);
