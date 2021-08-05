/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:19:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/05 10:04:40 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct s_parse_info {
	int exit_exists;
	int collect_exists;
	int player_exists;
	int	line_length;
}				t_parse_info;

typedef struct s_map_lines {
	char				*line;
	struct s_map_lines	*next;
}				t_map_lines;

/* linked_lists */
t_map_lines	*new_line(char *line);
void		free_list(t_map_lines *lst, int free_content);
int			size_of_list(t_map_lines *lst);
void		add_back_line(t_map_lines **lst, t_map_lines *new);

/* parser */
int parser(char *filename);
