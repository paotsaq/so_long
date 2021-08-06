/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 22:28:23 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx_mms_20200219/mlx.h"

# define ERROR_MSG "Error\n"

typedef struct s_parse_info {
	int exit_exists;
	int collect_exists;
	int player_exists;
	int	line_length;
}				t_parse_info;

typedef struct s_map {
	char				**map;
	int					lines_amount;
	int					p_pos[2];
	int					exit_pos[2];
	t_llist				c_pos;
}				t_map;

/* utils */
int	gets_map_fd(char *filename);
int	free_map_and_make_error(t_map *map_struct);

/* parser */
int parser(char *filename, t_map *map_struct);
