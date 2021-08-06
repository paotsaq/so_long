/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 08:47:45 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main()
{
	t_map map_struct;

	map_struct.map = NULL;
	map_struct.lines_amount = 0;

	if (parser("map.ber", &map_struct) == -1)
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	free_map_and_make_error(&map_struct);
}
