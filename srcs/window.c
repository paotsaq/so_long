/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:00:45 by apinto            #+#    #+#             */
/*   Updated: 2021/08/11 08:09:32 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_map_coordinates(int x, int y, t_map_coords *coords)
{
	coords->x = ASSET_WIDTH * x;
	coords->y = ASSET_HEIGHT * y;
}

void fill_first_map(t_game *game)
{
	int row;
	int column;
	t_map_coords coords;

	column = -1;
	while (++column < game->map.max_y)
	{
		row = -1;
		while (++row < game->map.max_x)
		{
			get_map_coordinates(row, column, &coords);
			if (game->map.map[column][row] == '0')
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
					game->i_asset_floor.img, coords.x, coords.y);
			else if (game->map.map[column][row] == '1')
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
					game->i_asset_wall.img, coords.x, coords.y);
			else if (game->map.map[column][row] == 'C')
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
					game->i_asset_coll.img, coords.x, coords.y);
			else if (game->map.map[column][row] == 'P')
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
					game->i_asset_player.img, coords.x, coords.y);
			else
				mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
					game->i_asset_exit.img, coords.x, coords.y);
		}
	}
}

void	initialize_window_and_instance(t_game *game)
{
	int window_width;
	int window_height;

	window_width = game->map.max_x * ASSET_WIDTH;
	window_height = game->map.max_y * ASSET_HEIGHT;
	game->mlx_instance = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_instance,
			window_width, window_height, "Hello world!");
}

int	window(t_game *game)
{
	if (load_textures(game) == -1)
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));

	initialize_window_and_instance(game);
	fill_first_map(game);

	mlx_loop(game->mlx_instance);
	return (1);
}
