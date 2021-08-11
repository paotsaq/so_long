/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/11 22:15:14 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx_mms_20200219/mlx.h"

# define ERROR_MSG		"Error\n"
# define ASSET_HEIGHT	99
# define ASSET_WIDTH	99

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

typedef struct 	s_game {
	char 		**map;
	void		*mlx_instance;
	void		*mlx_window;
	int			move_count;
	int			collectible_count;
	int			game_end;
	int			max_x;
	int			max_y;
	int			player_x;
	int			player_y;
	t_image		*image_to_write;
	t_image		i_asset_floor;
	t_image		i_asset_wall;
	t_image		i_asset_player;
	t_image		i_asset_coll;
	t_image		i_asset_exit;
}				t_game;

/* utils */
int	gets_map_fd(char *filename);
int	free_map_and_make_error(t_game *game);
void get_player_position(t_game *game);
void update_collectible_and_move_count(t_game *game, int x, int y);
int	legal_move(t_game *game, int x, int y);
int	game_finishes(t_game *game, int x, int y);
void	get_map_coordinates(int x, int y, t_map_coords *coords);

/* parser */
int parser(t_game *game, char *filename);

/* window */
int	window(t_game *game);

/* texture loading */
int	load_textures(t_game *game);
void	fill_first_map(t_game *game);

/* hooks */
int		on_key_press(int key, t_game *game);
void	make_a_move(t_game *game, int key);
