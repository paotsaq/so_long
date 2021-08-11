/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/11 02:01:55 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// should wrap error into an int function
int	main()
{
	t_game game;

	game.map.map = NULL;
	game.map.max_y = 0;

	if (parser(&game, "map.ber", &game.map) == -1)
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	window(&game);
	free_map_and_make_error(&game.map);
}
