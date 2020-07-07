/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:29:20 by mjander           #+#    #+#             */
/*   Updated: 2020/06/23 11:29:20 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void buildMatrix(char adjMatrix[MAX][MAX], room* roomList, r_link* links){
	int room1;
	int room2;
    initMatrix(adjMatrix);
	while (links) {
		room1 = findPos(roomList, links->roomA);
		room2 = findPos(roomList, links->roomB);
		adjMatrix[room1][room2] = '1';
		adjMatrix[room2][room1] = '1';
		links = links->next;
	}
}

void initMatrix(char adjMatrix[MAX][MAX]){
    int i = 0;
    int j = 0;
    while (i < MAX){
        j = i;
        while(j < MAX){
            adjMatrix[i][j] = '0';
		      adjMatrix[j][i] = '0';
            j++;
        }
        i++;
    }
}

int findPos(room* roomList, char *name){
	int i = 0;
	while(roomList){
		if (ft_strcmp(roomList->name, name) == 0){
			return i;
		}
      roomList = roomList->next;
		i++;
	}
	return -1;
}

room *findStart(room* roomList){
   while(roomList){
      if(roomList->type == 1){
         return roomList;
      }
      roomList = roomList->next;
   }
   return NULL;
}

void pushStack(int *stack, int *top, int index) { 
   stack[++(*top)] = index; 
} 

room *pop(int *stack, int *top, room *roomList) { 
   int index = stack[(*top)--]; 
   while(index--){
      roomList = roomList->next;
   }
   return roomList;
} 