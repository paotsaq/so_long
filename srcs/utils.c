/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 02:54:06 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 02:54:46 by apinto           ###   ########.fr       */
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
