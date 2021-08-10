/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/10 19:23:48 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_assets(t_game *game)
{
	load_texture(game, &game->asset_floor, "./assets/asset_grass.xpm");
	load_texture(game, &game->asset_exit, "./assets/asset_exit.xpm");
	load_texture(game, &game->asset_coll, "./assets/asset_coll.xpm");
	load_texture(game, &game->asset_wall, "./assets/asset_wall.xpm");
	load_texture(game, &game->asset_player, "./assets/asset_boy.xpm");
	if (game->asset_floor || game->asset_exit || game->asset_coll
			|| game->asset_wall || game->asset_player)
		return (-1);
	return (1);
}

// should wrap error into an int function 
int	main()
{
	t_game game;

	game.map.map = NULL;
	game.map.max_y = 0;

	if (parser(&game, "map.ber", &game.map) == -1)
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	if (load_assets(&game) == -1)
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	window(&game);
	free_map_and_make_error(&game.map);
}
