/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:00:45 by apinto            #+#    #+#             */
/*   Updated: 2021/08/10 17:53:41 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_to_image(t_game *game, t_image image)
{


}

int	window(t_game *game)
{
	t_image	data;

	game->mlx_instance = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_instance, 800, 300, "Hello world!");

	data.img = mlx_new_image(game->mlx_instance, 800, 300);
	data.addr = mlx_get_data_addr(data.img, 
				&data.bits_per_pixel, &data.line_length, &data.endian);


	mlx_put_image_to_window(game->mlx_instance, game->mlx_window, data.img, 0, 0);
	mlx_loop(game->mlx_instance);
	return (1);
}
