/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 08:49:28 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	initialize_parse_variables(t_parse_info *info)
{
	info->exit_exists = 0;
	info->collect_exists = 0;
	info->player_exists = 0;
}

static int	valid_line(t_parse_info *info, char *line, int first_or_last)
{
	if ((int)ft_strlen(line) != info->line_length)
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
		if (line[0] != '1' || line[info->line_length - 1] != '1')
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

static int	build_map_struct_matrix(t_map *map_struct, char *line)
{
	int		count;
	int		i;
	char	**lines;

	count = map_struct->lines_amount + 1;
	lines = ft_calloc(count, sizeof(char **));
	if (!lines)
		return (-1);
	i = -1;
	while (++i < map_struct->lines_amount)
		lines[i] = map_struct->map[i];
	lines[i] = line;
	if (map_struct->map)
		free(map_struct->map);
	map_struct->map = lines;
	map_struct->lines_amount++;
	return (1);
}

int	free_map_and_make_error(t_map *map_struct)
{
	int i = -1;

	while (++i < map_struct->lines_amount)
		free(map_struct->map[i]);
	free(map_struct->map);
	return (-1);
}

/* gets the file descriptor for the map reading,
 * parses the content and validates the input.
 * if successful, map gets updated as a side-effect,
 * otherwise, (-1) is returned */
int parser(char *filename, t_map *map_struct)
{
	int 			fd;
	char			*buffer;
	t_parse_info	parse_info;

	fd = gets_map_fd(filename);
	initialize_parse_variables(&parse_info);
	while (get_next_line(fd, &buffer) == 1)
	{
		if (map_struct->lines_amount == 0)
			parse_info.line_length = ft_strlen(buffer);
		if (valid_line(&parse_info, buffer, map_struct->lines_amount == 0))
			build_map_struct_matrix(map_struct, buffer);
		else
			return (free_map_and_make_error(map_struct));
	}
	if (!valid_line(&parse_info, buffer, 1))
		return (free_map_and_make_error(map_struct));
	return (1);
}
