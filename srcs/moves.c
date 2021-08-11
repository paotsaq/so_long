/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:09:48 by apinto            #+#    #+#             */
/*   Updated: 2021/08/11 08:42:10 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int on_key_press(int key, t_game *game)
{
	int x;
	int y;
	int result;

	x = game->map->player_coord_x;
	y = game->map->player_coord_y;
	if (key == ESC)
		printf("oops");
	else if (key == MOVE_UP || key == MOVE_DOWN || key == MOVE_LEFT || key == MOVE_RIGHT)
		move_player(&game->map.map[y][x], &game->map.map[y][x - 1], game->map->collectible_count);
	/*
	print_map(game);
	mlx_put_image_to_window(game->mlx_instance, game->window, game->img, 0, 0);
	*/
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
