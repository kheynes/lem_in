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
	r_link		*links;
	room		*roomList;
	char		**validPaths[50];
	int			antCount;
	int			likelyPaths;
	
	links = NULL;
	roomList = NULL;
	validPaths[0] = NULL;

	antCount = read_input(&roomList, &links);
	if(!has_room(roomList) || !includes_start_end(roomList)){
		freeRoomList(&roomList);
		free_links(&links);
		exit(1);
	}
	likelyPaths = depthFirstSearch(roomList, links, validPaths);
	if(!validPathCheck(validPaths)){
		freeRoomList(&roomList);
		free_links(&links);
		freeAllPaths(validPaths);
		exit(1);
	}
	printAllPaths(validPaths);
	ft_putstr("likely paths:");
	ft_putnbr(likelyPaths);
	ft_putchar('\n');
	moveAnts(validPaths, antCount, likelyPaths);
	freeRoomList(&roomList);
	free_links(&links);
	freeAllPaths(validPaths);
	return(0);
}