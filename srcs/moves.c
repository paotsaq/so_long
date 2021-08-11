/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:09:48 by apinto            #+#    #+#             */
/*   Updated: 2021/08/11 21:40:22 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int on_key_press(int key, t_game *game)
{
	int x;
	int y;

	x = game->player_x;
	y = game->player_y;
	if (key == ESC)
		printf("oops");
	else if (key == MOVE_UP || key == MOVE_DOWN || key == MOVE_LEFT || key == MOVE_RIGHT)
		move_player(game, key);
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

void	update_map_positions(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
}

void	refresh_two_tiles(t_game *game, int new_x, int new_y)
{
	t_map_coords	coords;
	t_image			*asset;

	if (game->map[game->player_y][game->player_x] == 'E')
		asset = &game->i_asset_exit;
	else
		asset = &game->i_asset_floor;
	get_map_coordinates(game->player_x, game->player_y, &coords);
	mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
		asset->img, coords.x, coords.y);
	get_map_coordinates(new_x, new_y, &coords);
	asset = &game->i_asset_player;
	mlx_put_image_to_window(game->mlx_instance, game->mlx_window,
		asset->img, coords.x, coords.y);
}

void	move_player(t_game *game, int key)
{
	int new_x;
	int	new_y;

	if (key == MOVE_UP || key == MOVE_DOWN)
	{
		if (key == MOVE_UP)
			new_y = game->player_y - 1;
		else
			new_y = game->player_y + 1;
		new_x = game->player_x;
	}
	else
	{
		if (key == MOVE_LEFT)
			new_x = game->player_x - 1;
		else
			new_x = game->player_x + 1;
		new_y = game->player_y;
	}
	printf("%d %d %d %d\n", game->player_x, game->player_y, new_x, new_y);
	if (!legal_move(game, new_x, new_y))
		return;
	printf("is legal\n");
	update_collectible_and_move_count(game, new_x, new_y);
	refresh_two_tiles(game, new_x, new_y);
	update_map_positions(game, new_x, new_y);
	game_finishes(game, new_x, new_y);
	fill_first_map(game);
}
