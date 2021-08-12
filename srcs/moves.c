/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:09:48 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 20:22:51 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		exit_hook(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->max_y)
		free(game->map[i]);
	free(game->map);
	mlx_destroy_image(game->mlx_instance, game->i_asset_floor.img);
	mlx_destroy_image(game->mlx_instance, game->i_asset_exit.img);
	mlx_destroy_image(game->mlx_instance, game->i_asset_coll.img);
	mlx_destroy_image(game->mlx_instance, game->i_asset_wall.img);
	mlx_destroy_image(game->mlx_instance, game->i_asset_player.img);
	mlx_destroy_image(game->mlx_instance, game->i_asset_player_over_exit.img);
	mlx_destroy_window(game->mlx_instance, game->mlx_window);
	exit(0);
	return (1);
}

/* introduces new map letter, 'N', that stands for player being over the exit,
 * bi_asset_exit;ut still now allowed to make the game finish */
void	update_map_positions(t_game *game, int new_x, int new_y)
{
	if (game->map[game->player_y][game->player_x] == 'N')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	if (game->map[new_y][new_x] == 'E')
		game->map[new_y][new_x] = 'N';
	else
		game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
}

/* after the first render of the whole map, only two additional renders
 * per move are needed; the position the player left, and the
 * position the player is at. This function handles those two. */
void	refresh_two_tiles(t_game *game, int new_x, int new_y)
{
	t_map_coords	coords;
	t_image			*asset;

	if (game->map[game->player_y][game->player_x] == 'N')
		asset = &game->i_asset_exit;
	else
		asset = &game->i_asset_floor;
	get_map_coordinates(game->player_x, game->player_y, &coords);
	render_asset(game, asset, &coords);
	if (game->map[new_y][new_x] == 'E')
		asset = &game->i_asset_player_over_exit;
	else
		asset = &game->i_asset_player;
	get_map_coordinates(new_x, new_y, &coords);
	render_asset(game, asset, &coords);
}

void	update_provisional_positions(t_game *game, int key)
{
	if (key == MOVE_UP || key == MOVE_DOWN)
	{
		if (key == MOVE_UP)
			game->new_y = game->player_y - 1;
		else
			game->new_y = game->player_y + 1;
		game->new_x = game->player_x;
	}
	else
	{
		if (key == MOVE_LEFT)
			game->new_x = game->player_x - 1;
		else
			game->new_x = game->player_x + 1;
		game->new_y = game->player_y;
	}
}

int	on_key_press(int key, t_game *game)
{
	int x;
	int y;

	x = game->player_x;
	y = game->player_y;
	if (key == ESC)
		exit_hook(game);
	else if (game->allow_movement && (key == MOVE_UP || key == MOVE_DOWN ||
			key == MOVE_LEFT || key == MOVE_RIGHT))
	{
		update_provisional_positions(game, key);
		if (legal_move(game, game->new_x, game->new_y))
		{
			update_collectible_and_move_count(game, game->new_x, game->new_y);
			refresh_two_tiles(game, game->new_x, game->new_y);
			update_map_positions(game, game->new_x, game->new_y);
			ft_putnbr_fd(game->move_count, 1);
			ft_putchar_fd('\n', 1);
			if (game_finishes(game, game->player_x, game->player_y))
				game->allow_movement = 0;
		}
	}
	return (0);
}
