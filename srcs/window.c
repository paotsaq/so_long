/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:00:45 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 15:54:27 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_asset(t_game *game, t_image *asset, t_map_coords *coords)
{
	mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
		asset->img, coords->x, coords->y);
}

void	get_map_coordinates(int x, int y, t_map_coords *coords)
{
	coords->x = ASSET_WIDTH * x;
	coords->y = ASSET_HEIGHT * y;
}

void	fill_first_map(t_game *game)
{
	int row;
	int column;
	t_map_coords coords;
	t_image	*asset;

	column = -1;
	while (++column < game->max_y)
	{
		row = -1;
		while (++row < game->max_x)
		{
			get_map_coordinates(row, column, &coords);
			if (game->map[column][row] == '0')
				asset = &game->i_asset_floor;
			else if (game->map[column][row] == '1')
				asset = &game->i_asset_wall;
			else if (game->map[column][row] == 'C')
				asset = &game->i_asset_coll;
			else if (game->map[column][row] == 'P')
				asset = &game->i_asset_player;
			else
				asset = &game->i_asset_exit;
			render_asset(game, asset, &coords);
		}
	}
}

void	initialize_window_and_instance(t_game *game)
{
	int window_width;
	int window_height;

	window_width = game->max_x * ASSET_WIDTH;
	window_height = game->max_y * ASSET_HEIGHT;
	game->mlx_instance = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_instance,
			window_width, window_height, "So Long 🐬");
}

int	makes_window(t_game *game)
{
	initialize_window_and_instance(game);
	if (load_textures(game) == -1)
	{
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
		return (-1);
	}
	fill_first_map(game);
	return (1);
}
