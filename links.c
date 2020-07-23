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

void	make_links_list(r_link **links, char *line, room **roomList)
{
	char	**input;
	char	*roomA;
	char	*roomB;
	int 	i;
	
	i = 0;
	input = ft_strsplit(line, '-');
	if (input[1])
	{
		roomA = ft_strtrim(input[0]);
		roomB = ft_strtrim(input[1]);
		push_link(links, roomA, roomB);
		while (input[i])
		{
			free(input[i++]);
		}
	}
	else
	{
		ft_putendl("\033[0;31mError: Invalid link\033[0m");
		while (input[i])
		{
			free(input[i++]);
		}
		free(input);
		free(line);
		freeRoomList(roomList);
		free_links(links);
		exit(1);
	}
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
}