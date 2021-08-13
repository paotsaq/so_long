/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 19:38:00 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx_mms_20200219/mlx.h"

# define ERROR_MSG		"Error\n"
# define ASSET_HEIGHT	99
# define ASSET_WIDTH	99
# define DESTROY_NOTIFY	17
# define ESC			53
# define MOVE_UP 		13
# define MOVE_DOWN 		1
# define MOVE_RIGHT 	2
# define MOVE_LEFT		0

# define WRONG_ARGC		"Wrong number of arguments.\n"
# define NOT_RECTANGLE	"Map is not a rectangle.\n"
# define BORDER_NOT_1	"One of the borders is illegal.\n"
# define MSSNG_EPC		"Map is missing player, exit, or collectible.\n"
# define MALLOC_FAIL	"Allocation failed.\n"
# define FILE_R_FAIL	"File reading failed.\n"

typedef struct s_map_coords {
	int	x;
	int	y;
}				t_map_coords;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
}				t_image;

typedef struct s_parse_info {
	int		exit_exists;
	int		collect_exists;
	int		player_exists;
}				t_parse_info;

typedef struct s_game {
	char		**map;
	void		*mlx_instance;
	void		*mlx_window;
	int			move_count;
	int			collectible_count;
	int			game_end;
	int			max_x;
	int			max_y;
	int			player_x;
	int			player_y;
	int			new_x;
	int			new_y;
	int			allow_movement;
	t_image		i_asset_floor;
	t_image		i_asset_wall;
	t_image		i_asset_player;
	t_image		i_asset_player_over_exit;
	t_image		i_asset_coll;
	t_image		i_asset_exit;
}				t_game;

/* utils */
int		gets_map_fd(t_game *game, char *filename);
void	update_map_information(t_game *game, int collectible_count);
void	update_collectible_and_move_count(t_game *game, int x, int y);
int		legal_move(t_game *game, int x, int y);
int		game_finishes(t_game *game, int x, int y);
void	get_map_coordinates(int x, int y, t_map_coords *coords);

/* frees && memory_management */
int		error_and_free(t_game *game, char *message, int layers);
void	free_map(t_game *game);

/* parser */
int		parser(t_game *game, char *filename);

/* window */
int		makes_window(t_game *game);
void	render_asset(t_game *game, t_image *asset, t_map_coords *coords);

/* texture loading */
int		load_textures(t_game *game);
void	fill_first_map(t_game *game);

/* hooks */
int		on_key_press(int key, t_game *game);
void	make_a_move(t_game *game, int key);
int		exit_hook(t_game *game);
