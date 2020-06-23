/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:29:20 by kheynes           #+#    #+#             */
/*   Updated: 2020/06/23 11:29:20 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		array_len(char **rooms)
{
	int     size;

	size = 0;
	while(rooms[size] != NULL)
	{
		size++;
	}
	return (size);
}

int		is_room_link(char *line)
{
	char    **rooms;

	rooms = ft_strsplit(line, '-');
	if (array_len(rooms) == 2)
		return(1);
	else
		return(0);
}

void	make_links_list(t_link **link, char *line)
{
	char	**input;
	char	*roomA;
	char	*roomB;

	input = ft_strsplit(line, '-');
	roomA = input[0];
	roomB = input[1];
	push_link(link, roomA, roomB);
}