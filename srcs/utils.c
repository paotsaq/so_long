/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 02:54:06 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 16:14:41 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	gets_map_fd(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

void	update_map_information(t_game *game, int count_collectibles)
{
	int	x;
	int	y;

	if (count_collectibles)
		game->collectible_count = 0;
	y = -1;
	while(++y < game->max_y)
	{
		x = -1;
		while(++x < game->max_x)
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (count_collectibles && game->map[y][x] == 'C')
				game->collectible_count++;
	}
}

int		game_finishes(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'N' && game->collectible_count == 0)
		return (1);
	else
		return (0);
}

int	legal_move(t_game *game, int x, int y)
{
	return (x < game->max_x && y < game->max_y
			&& game->map[y][x] != '1');
}

void	update_collectible_and_move_count(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		printf("found a collectible!\n");
		game->collectible_count--;
	}
	game->move_count++;
}
