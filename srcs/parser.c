/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 15:57:56 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	initialize_parse_variables(t_parse_info *info)
{
	info->exit_exists = 0;
	info->collect_exists = 0;
	info->player_exists = 0;
}

static int	valid_line(t_game *game, t_parse_info *info, char *line, int first_or_last)
{
	if ((int)ft_strlen(line) != game->max_x)
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
		if (line[0] != '1' || line[game->max_x - 1] != '1')
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
static int	allocate_map_matrix(t_game *game, char *line)
{
	int		count;
	int		i;
	char	**lines;

	count = game->max_y + 1;
	lines = ft_calloc(count, sizeof(char **));
	if (!lines)
		return (-1);
	i = -1;
	while (++i < game->max_y)
		lines[i] = game->map[i];
	lines[i] = line;
	if (game->map)
		free(game->map);
	game->map = lines;
	game->max_y++;
	return (1);
}

int	free_map_and_make_error(t_game *game)
{
	int i = -1;

	while (++i < game->max_y)
		free(game->map[i]);
	free(game->map);
	return (-1);
}

/* gets the file descriptor for the map reading,
 * parses the content, and validates the input.
 * if successful,
 *		map gets updated as a side-effect,
 * otherwise,
 *		(-1) is returned
 * the buffer is freed afterwards,
 * because GNL will still alocate a null string. */
int parser(t_game *game, char *filename)
{
	int 			fd;
	char			*buffer;
	t_parse_info	parse_info;

	fd = gets_map_fd(filename);
	initialize_parse_variables(&parse_info);
	while (get_next_line(fd, &buffer) == 1)
	{
		if (game->max_y == 0)
			game->max_x = ft_strlen(buffer);
		if (valid_line(game, &parse_info, buffer, game->max_y == 0))
			allocate_map_matrix(game, buffer);
		else
			return (free_map_and_make_error(game));
	}
	if (!valid_line(game, &parse_info, buffer, 1))
		return (free_map_and_make_error(game));
	update_map_information(game, 1);
	free(buffer);
	return (1);
}
