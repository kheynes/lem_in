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
	//char    **rooms;
	int i = 0;
	while (line[i++]){
		if (line[i] == '-' && i != 0){
			return 1;
		}
	}

	// ret = 0;
	// rooms = ft_strsplit(line, '-');
	// if (array_len(rooms) == 2){
	// 	ret = 1;
	// }	
	// free(rooms[0]);
	// free(rooms[1]);
	// free(*rooms);
	return 0;
}

void	make_links_list(r_link **links, char *line)
{
	char	**input;
	char	*roomA;
	char	*roomB;

	input = ft_strsplit(line, '-');
	roomA = input[0];
	roomB = input[1];
	push_link(links, roomA, roomB);
	free(input);
	
}

void	free_links(r_link **links){
	r_link	*current = *links;
	r_link	*next;
	while (current != NULL){
		next = current->next;
		free(current->roomA);
		free(current->roomB);
		free(current);
		current = next;
	}
	*links = NULL;
}