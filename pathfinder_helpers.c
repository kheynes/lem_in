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
            adjMatrix[i][j] = 0;
		      adjMatrix[j][i] = 0;
            j++;
        }
        i++;
    }
}

void  removeFromMatrix(int room1, int room2, char adjMatrix[MAX][MAX]){
      adjMatrix[room1][room2] = 0;
		adjMatrix[room2][room1] = 0;   
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

void push(room **potentialPath, room *step, int *stepCount) {
   potentialPath[(*stepCount)++] = step;
   potentialPath[(*stepCount)] = NULL;
}

void pop(room **potentialPath, int *stepCount) {
   potentialPath[(*stepCount) - 1] = NULL;
   (*stepCount)--;
}

room *getNextRoom(char adjMatrix[MAX][MAX], room *start, room *roomList) {
   int i = 0;
   int roomIndex;
   roomIndex = start->index;
   while(roomList) {
        if(adjMatrix[roomIndex][i] && roomList->dist == -1) {
                return roomList;
        }
        i++;
        roomList = roomList->next;
   }
   return NULL;
}

void addToValidPaths(room **path, char ***validPaths, int *stepCount, int *pathCount){
   int i;
   char** newPath = NULL;
   newPath = (char**) malloc(sizeof(char*) * (*stepCount) + 8);
   i = 0;
   while(i < (*stepCount)){
      newPath[i] = path[i]->name;
      i++;
   }
   newPath[i] = NULL;
   validPaths[(*pathCount)++] = newPath;
   validPaths[(*pathCount)] = NULL;
}