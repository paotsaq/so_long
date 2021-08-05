/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:17:18 by apinto            #+#    #+#             */
/*   Updated: 2021/08/05 10:20:57 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	initialize_parse_variables(t_parse_info *info, t_map_lines **lines)
{
	info->exit_exists = 0;
	info->collect_exists = 0;
	info->player_exists = 0;
	*lines = NULL;
}

static int	valid_line(t_parse_info *info, char *line, int first_or_last)
{
	if (ft_strlen(line) != info->line_length)
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
				|| *line == 'E' && info->exit_exists++ > 1
				|| *line == 'P' && info->player_exists++ > 1
				|| *line == 'C' && info->collect_exists++ > 1)
				return (-1);
			else
				line++;
	}
	return (1);
}

static int	gets_map_fd(char *filename)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	return (1);
}

static int	frees_list(t_map_lines **list, int free_content)
{
	free_list(*list, free_content);
	if (free_content)
		return (-1);
	else
		return (1);
}

int parser(char *filename)
{
	int 			fd;
	char			*buffer;
	t_parse_info	parse_info;
	t_map_lines		**lines;

	fd = gets_map_fd(filename);
	initialize_parse_variables(&parse_info, lines);
	while (get_next_line(fd, &buffer) == 1)
	{
		if (*lines == NULL)
			parse_info.line_length = ft_strlen(buffer);
		if (valid_line(&parse_info, buffer, *lines == NULL))
			add_back_line(lines, new_line(buffer));
		else
			return (frees_list(lines, 1));
	}
	if (!valid_line(&parse_info, buffer, 1))
		return (frees_list(lines, 1));
	return (1);
}