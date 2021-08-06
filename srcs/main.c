/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 02:53:07 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main()
{
	t_map_lines lines;

	if (parser("map.ber", &lines) == -1)
		write(STDOUT_FILENO, ERROR_MSG, ft_strlen(ERROR_MSG));
	else
	{

	}

}
