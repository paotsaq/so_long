/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/11 08:36:31 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx_mms_20200219/mlx.h"

# define ERROR_MSG		"Error\n"
# define ASSET_HEIGHT	100
# define ASSET_WIDTH	100
# define ESC			53
# define MOVE_UP 		13
# define MOVE_DOWN 		1
# define MOVE_RIGHT 	2
# define MOVE_LEFT		0

typedef struct s_map_coords {
	int x;
	int y;
}				t_map_coords;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
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
	int			key_count;
	t_image		*image_to_write;
	t_image		i_asset_floor;
	t_image		i_asset_wall;
	t_image		i_asset_player;
	t_image		i_asset_coll;
	t_image		i_asset_exit;
}				t_game;

/* utils */
int	gets_map_fd(char *filename);
int	free_map_and_make_error(t_map *map_struct);
void get_player_position(t_map *map_struct, char *line);

/* parser */
int parser(t_game *game, char *filename, t_map *map_struct);

/* window */
int	window(t_game *game);

/* texture loading */
int	load_textures(t_game *game);
