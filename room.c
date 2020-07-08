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

room* newRoom(char *name, int type){
   room     *newRoom;
   newRoom = (room*)malloc(sizeof(room));
   ft_strcpy(newRoom->name, name);
   newRoom->visited = 0; 
   newRoom->type = type;  
   newRoom->dist = -1;   
   newRoom->prev = NULL;   
   newRoom->next = NULL; 
   return newRoom;
}

void add_room(room **roomList, char *name, int type){
   room *newNode;
   newNode = newRoom(name, type);
   newNode->next = *roomList;
   *roomList = newNode;
}

void reverse(room **roomList){
   room *prev = NULL;
   room *current = *roomList;
   room *next = NULL;
   int index = 0;
   while(current){
      next = current->next;
      current->next = prev; 
      prev = current; 
      current = next; 
   }
   *roomList = prev;
   current = *roomList;
   while(current){
      current->index = index++;
      current = current->next;
   }
}

void reset_rooms(room **roomList){
   room *temp = *roomList;
   while(temp){
      temp->dist = -1;
      temp->prev = NULL; 
      temp = temp->next;
   }
}

void		print_rooms(room *head)
{
	room		*temp;

	temp = head;

	while(temp)
	{
      ft_putstr("name:");
		ft_putstr(temp->name);
		ft_putstr(" type:");
		ft_putnbr(temp->type);
		ft_putstr("\n");
		temp = temp->next;
	}
}

int nbrOfRooms(room *roomList){
   int i = 0;
   while(roomList){
      i++;
      roomList = roomList->next;
   }
   return i;
}

void freeRoomList(room **roomList){
   room	*current = *roomList;
	room	*next;
	while (current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
}



