/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 12:16:37 by kheynes           #+#    #+#             */
/*   Updated: 2020/05/31 12:16:37 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     main()
{
	room		*roomList[MAX];
	char		**validPaths[MAX];
	r_link		*links;
	int			antCount;
	int			likelyPaths;

	links = NULL;
	roomList[0] = NULL;

	antCount = read_input(roomList, &links);
	
	has_room(roomList);
	includes_start_end(roomList);
	likelyPaths = depthFirstSearch(roomList, links, validPaths);
	
	//printAllPaths(validPaths);
	moveAnts(validPaths, antCount, likelyPaths);
	freeRoomList(roomList);
	free_links(&links);
	freeAllPaths(validPaths);
	return(0);
}