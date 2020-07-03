/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:03:41 by kheynes           #+#    #+#             */
/*   Updated: 2020/05/31 21:03:41 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void addRoom(room **roomList, char *name, int type, int *roomCount) {
	room	*newRoom;
   newRoom = (room*)malloc(sizeof(room));
   ft_memset(newRoom->name, '\0', sizeof(newRoom->name));
   ft_strcpy(newRoom->name, name);
   newRoom->visited = 0; 
   newRoom->type = type;     
   roomList[(*roomCount)++] = newRoom;
   roomList[*roomCount] = NULL;
}

void freeRoomList(room **roomList){
   int i = 0;
   while (roomList[i]){
      free(roomList[i++]->name);
      free(roomList[i++]);
   }
}



