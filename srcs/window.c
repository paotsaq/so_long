/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:00:45 by apinto            #+#    #+#             */
/*   Updated: 2021/08/09 20:33:18 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	window(void)
{
	void	*mlx_instance;
	void	*mlx_win;
	t_image	data;

	mlx_instance = mlx_instance_init();
	mlx_win = mlx_new_window(mlx, 800, 300, "Hello world!");
	data.img = mlx_new_image(mlx, 800, 300);

	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);
	return (1);
}
