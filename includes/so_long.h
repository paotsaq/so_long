/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/07 19:18:59 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx_mms_20200219/mlx.h"

# define ERROR_MSG "Error\n"

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_parse_info {
	int exit_exists;
	int collect_exists;
	int player_exists;
	int	line_length;
}				t_parse_info;

typedef struct	s_coll_lst {
	int					x;
	int					y;
	struct s_coll_lst	*next;
}				t_coll_lst;

typedef struct s_map {
	char				**map;
	int					lines_amount;
	int					player_x;
	int					player_y;
	int					exit_x;
	int					exit_y;
	t_coll_lst			**c_pos;
}				t_map;

/* utils */
int	gets_map_fd(char *filename);
int	free_map_and_make_error(t_map *map_struct);
int	add_back_collectible(t_coll_lst **lst, t_coll_lst *new);
t_coll_lst	*new_collectible(int x, int y);

/* parser */
int parser(char *filename, t_map *map_struct);

/* window */
int	window(void);
