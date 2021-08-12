/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 16:09:09 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main()
{
	t_game game;

	game.map = NULL;
	game.max_y = 0;
	game.move_count = 0;
	game.allow_movement = 1;

	if (parser(&game, "map.ber") == -1)
	{
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
		return (-1);
	}
	makes_window(&game);
	mlx_key_hook(game.mlx_window, on_key_press, &game);
	mlx_loop(game.mlx_instance);
	return (0);
}
