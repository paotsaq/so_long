/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 19:40:44 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_and_free(t_game *game, char *message, int layers)
{
	if (layers == 1)
	{
		free_map(game);
		layers--;
	}
	write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(1, message, ft_strlen(message));
	return (-1);
}

static void	init_game_variables(t_game *game)
{
	game->map = NULL;
	game->max_y = 0;
	game->move_count = 0;
	game->allow_movement = 1;
}

int	gets_map_fd(t_game *game, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_and_free(game, FILE_R_FAIL, 0));
	return (fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_and_free(&game, WRONG_ARGC, 0));
	init_game_variables(&game);
	if (parser(&game, argv[1]) == -1)
		return (-1);
	makes_window(&game);
	mlx_key_hook(game.mlx_window, on_key_press, &game);
	mlx_hook(game.mlx_window, DESTROY_NOTIFY, 1L, exit_hook, &game);
	mlx_loop(game.mlx_instance);
	return (0);
}
