/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:44:23 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 07:35:20 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	xpm_to_image_wrapper(t_game *game, t_image *image, char *filename)
{
	image->img = mlx_xpm_file_to_image(game->mlx_instance,
			filename, &image->img_width, &image->img_height);
	if (!image->img)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	xpm_to_image_wrapper(game, &game->i_asset_floor,
		"./assets/asset_grass.xpm");
	xpm_to_image_wrapper(game, &game->i_asset_exit,
		"./assets/asset_exit.xpm");
	xpm_to_image_wrapper(game, &game->i_asset_coll,
		"./assets/asset_coll.xpm");
	xpm_to_image_wrapper(game, &game->i_asset_wall,
		"./assets/asset_wall.xpm");
	xpm_to_image_wrapper(game, &game->i_asset_player,
		"./assets/asset_boy.xpm");
	xpm_to_image_wrapper(game, &game->i_asset_player_over_exit,
		"./assets/asset_boy_over_exit.xpm");
	if (!game->i_asset_floor.img || !game->i_asset_exit.img
		|| !game->i_asset_coll.img || !game->i_asset_wall.img
		|| !game->i_asset_player.img || !game->i_asset_player_over_exit.img)
		return (-1);
	return (1);
}
