/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:57:35 by apinto            #+#    #+#             */
/*   Updated: 2021/08/06 22:38:43 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* this could be a little more abstract;
 * here's to hoping I won't need any more structs */
t_coll_lst	*new_collectible(int x, int y)
{
	t_coll_lst	*res;

	res = malloc(sizeof(t_coll_lst));
	if (res == 0)
		return (NULL);
	res->x = x;
	res->y = y;
	res->next = NULL;
	return (res);
}

int		add_back_collectible(t_coll_lst **lst, t_coll_lst *new)
{
	t_coll_lst	*last;

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

int		size_of_list(t_coll_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	free_list(t_coll_lst *lst)
{
	t_coll_lst *next;

	while(lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}
