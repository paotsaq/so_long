/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:44:23 by apinto            #+#    #+#             */
/*   Updated: 2021/08/10 17:56:44 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	**allocate_image_matrix()
{
	int **new_image;
	int i;

	i = -1;
	new_image = ft_malloc(ASSET_HEIGHT * sizeof(*int));
	if (!new_image)
		return (NULL);
	while (++i < ASSET_HEIGHT)
	{
		*image[i] = ft_malloc(ASSET_WIDTH * sizeof(int));
		if (!(*image[i]))
			return (NULL);
	}
	return (new_image);
}

void	load_texture(t_game *game, int ***pointer, char *path_to_file)
{
	t_image new_image;
	int		x;
	int		y;
	int		**image;

	image = allocate_image_matrix();
	if (!image)
		return (-1);
	new_image.img = mlx_xpm_file_to_image(game->mlx_instance,
			path_to_file, &new_image.img_width, &new_image.img_heigth);
	if (!new_image.img)
		return (-1);
	y = -1;
	while (++y < new_image.img_heigth)
	{
		x = -1;
		while (++y < new_image.img_width)
			image[y][x] = *(int *)(new_image.addr + 
					(y * new_image.line_length + 
					 (x * (new_image.bits_per_pixel / 8))));
	}
	mlx_destroy_image(new_image);
	return (image);
}
