/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/10 16:36:10 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	initialize_parse_variables(t_parse_info *info)
{
	info->exit_exists = 0;
	info->collect_exists = 0;
	info->player_exists = 0;
}

static int	valid_line(t_game *game, t_parse_info *info, char *line, int first_or_last)
{
	if ((int)ft_strlen(line) != game->map.max_x)
		return (-1);
	if (first_or_last)
	{
		while (*line)
			if (*line != '1')
				return (-1);
			else
				line++;
	}
	else
	{
		if (line[0] != '1' || line[game->map.max_x - 1] != '1')
			return (-1);
		while (*line)
			if (!ft_strchr("01ECP", *line)
				|| (*line == 'E' && info->exit_exists++ > 1)
				|| (*line == 'P' && info->player_exists++ > 1)
				|| (*line == 'C' && info->collect_exists++ > 1))
				return (-1);
			else
				line++;
	}
	return (1);
}

/* line count can be used in here? */
static int	allocate_map_matrix(t_map *map_struct, char *line)
{
	int		count;
	int		i;
	char	**lines;

	count = map_struct->max_y + 1;
	lines = ft_calloc(count, sizeof(char **));
	if (!lines)
		return (-1);
	i = -1;
	while (++i < map_struct->max_y)
		lines[i] = map_struct->map[i];
	lines[i] = line;
	if (map_struct->map)
		free(map_struct->map);
	map_struct->map = lines;
	map_struct->max_y++;
	return (1);
}

int	free_map_and_make_error(t_map *map_struct)
{
	int i = -1;

	while (++i < map_struct->max_y)
		free(map_struct->map[i]);
	free(map_struct->map);
	return (-1);
}

void	get_player_position(t_map *map_struct, char *line)
{
	int	x;
	int	y;

	y = -1;
	while(++y < map_struct->max_y)
	{
		x = -1;
		while(++x < map_struct->max_x)
			if (line[x] == 'P')
			{
				map_struct->player_x = x;
				map_struct->player_y = y;
			}
	}
}

/* gets the file descriptor for the map reading,
 * parses the content, and validates the input.
 * if successful,
 *		map gets updated as a side-effect,
 * otherwise,
 *		(-1) is returned
 * the buffer is freed afterwards,
 * because GNL will still alocate a null string. */
int parser(t_game *game, char *filename, t_map *map_struct)
{
	int 			fd;
	char			*buffer;
	t_parse_info	parse_info;
	int				line_number;

	line_number = 0;
	fd = gets_map_fd(filename);
	initialize_parse_variables(&parse_info);
	while (get_next_line(fd, &buffer) == 1)
	{
		if (map_struct->max_y == 0)
			map_struct->max_x = ft_strlen(buffer);
		if (valid_line(game, &parse_info, buffer, game->map.max_y == 0))
			allocate_map_matrix(&game->map, buffer);
		else
			return (free_map_and_make_error(&game->map));
		line_number++;
	}
	if (!valid_line(game, &parse_info, buffer, 1))
		return (free_map_and_make_error(&game->map));
	free(buffer);
	return (1);
}
