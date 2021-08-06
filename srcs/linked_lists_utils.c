/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:57:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 01:55:31 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map_lines	*new_line(char *line)
{
	t_map_lines	*res;

	res = malloc(sizeof(t_map_lines));
	if (res == 0)
		return (NULL);
	res->line = line;
	res->next = NULL;
	return (res);
}

int		add_back_line(t_map_lines **lst, t_map_lines *new)
{
	t_map_lines	*last;

	if (lst && new)
	{
		last = *lst;
		if (!last)
			*lst = new;
		else
		{
			while (last->next)
				last = last->next;
			last->next = new;
			return (1);
		}
	}
	return (-1);
}

int	size_of_list(t_map_lines *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = (*lst).next;
	}
	return (i);
}

void	free_list(t_map_lines *lst, int free_content)
{
	t_map_lines *next;

	while(lst)
	{
		next = lst->next;
		if (free_content)
			free(lst->line);
		free(lst);
		lst = next;
	}
}
