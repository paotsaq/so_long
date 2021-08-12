/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/12 20:11:57 by apinto           ###   ########.fr       */
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
		return (error_and_free(game, NOT_RECTANGLE, 1));
	if (first_or_last)
	{
		while (*line)
			if (*line != '1')
				return (error_and_free(game, BORDER_NOT_1, 1));
			else
				line++;
	}
	else
	{
		if (line[0] != '1' || line[game->max_x - 1] != '1')
			return (error_and_free(game, BORDER_NOT_1, 1));
		while (*line)
			if (!ft_strchr("01ECP", *line)
				|| (*line == 'E' && info->exit_exists++ < 0)
				|| (*line == 'P' && info->player_exists++ < 0)
				|| (*line == 'C' && info->collect_exists++ < 0))
				return (error_and_free(game, MSSNG_EPC, 1));
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
		return (error_and_free(game, MALLOC_FAIL, 1));
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

	fd = gets_map_fd(game, filename);
	initialize_parse_variables(&parse_info);
	while (get_next_line(fd, &buffer) == 1)
	{
		if (game->max_y == 0)
			game->max_x = ft_strlen(buffer);
		if (valid_line(game, &parse_info, buffer, game->max_y == 0) == 1)
			allocate_map_matrix(game, buffer);
		else
			return (-1);
	}
	free(buffer);
	if (parse_info.exit_exists == 0 ||
		parse_info.player_exists != 1 ||
		parse_info.collect_exists == 0)
		return (error_and_free(game, MSSNG_EPC, 1));
	update_map_information(game, 1);
	return (1);
}
