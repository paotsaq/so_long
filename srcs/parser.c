/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 03:04:08 by apinto           ###   ########.fr       */
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

/* wraps the free_list function,
 * returning -1 to propagate error to parser*/
static int	free_list_and_make_error(t_map_lines **list, int free_content)
{
	free_list(*list, free_content);
	return (-1);
}

// int	builds_map()

/* gets the file descriptor for the map reading,
 * parses the content and validates the input.
 * if successful, lines gets updated as a side-effect,
 * otherwise, (-1) is returned */
int parser(char *filename, t_map_lines *lines)
{
	int 			fd;
	char			*buffer;
	t_parse_info	parse_info;

	lines = NULL;
	fd = gets_map_fd(filename);
	initialize_parse_variables(&parse_info);
	while (get_next_line(fd, &buffer) == 1)
	{
		if (lines == NULL)
			parse_info.line_length = ft_strlen(buffer);
		if (valid_line(&parse_info, buffer, lines == NULL))
			add_back_line(&lines, new_line(buffer));
		else
			return (free_list_and_make_error(&lines, 1));
	}
	if (!valid_line(&parse_info, buffer, 1))
		return (free_list_and_make_error(&lines, 1));
	return (1);
}
