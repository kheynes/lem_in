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

int depthFirstSearch(room* roomList, r_link* links, char ***validPaths) {
   room *potentialPath[MAX];
   int stepCount = 0;
   int pathCount = 0;
   room *start = findStart(roomList);
   room *stack[MAX]; 
   int top = -1; 
   int adjMatrix[MAX][MAX];
   buildMatrix(adjMatrix, roomList, links);
   findAllPathsUtil(adjMatrix, start, roomList, potentialPath, &stepCount, validPaths, &pathCount, stack, &top);
   sortPaths(validPaths);
   return (getNumOfAdjRooms(adjMatrix, start, roomList));
}

void findAllPathsUtil(int adjMatrix[MAX][MAX], room *start, room* roomList, room **potentialPath, int *stepCount, char ***validPaths, int *pathCount, room **stack, int *top){
   int adjRooms;
   room *unvisitedRoom = NULL;
   addToPotentialPath(potentialPath, start, stepCount);
   pushStack(stack, top, start);
   start->visited = 1;

   if (start->type == 2) {
      addToValidPaths(potentialPath, validPaths, stepCount, pathCount);
   }
   else {
      adjRooms = getNumOfAdjRooms(adjMatrix, start, roomList);
      while (adjRooms > 0){
         unvisitedRoom = getNextUnvisitedRoom(adjMatrix, start, roomList, adjRooms);
         findAllPathsUtil(adjMatrix, unvisitedRoom, roomList, potentialPath, stepCount, validPaths, pathCount, stack, top);
         adjRooms--;
      }
   }
   removeFromPotentialPath(potentialPath, stepCount);
   pop(stack, top)->visited = 0;
}

int getNumOfAdjRooms(int adjMatrix[MAX][MAX], room *start, room *roomList){
   int i = 0;
   int num = 0;
   int roomIndex;
   roomIndex = findPos(roomList, start->name);
   while(roomList){
      if(adjMatrix[roomIndex][i] == 1 && roomList->visited == 0) {
        num++;
      }
      i++; 
      roomList = roomList->next;
   }
   return num;
}
room *getNextUnvisitedRoom(int adjMatrix[MAX][MAX], room *start, room *roomList, int num) {
   int i = 0;
   int roomIndex;
   roomIndex = findPos(roomList, start->name);
   while(roomList) {
      if(adjMatrix[roomIndex][i] == 1 && roomList->visited == 0) {
         num--;
         if (num == 0){
            return roomList;
         }
      }
      i++;
      roomList = roomList->next;
   }
   return NULL;
}

void addToPotentialPath(room **potentialPath, room *step, int *stepCount) {
   potentialPath[(*stepCount)++] = step;
}

void removeFromPotentialPath(room **potentialPath, int *stepCount) {
   potentialPath[(*stepCount) - 1] = NULL;
   (*stepCount)--;
}

void addToValidPaths(room **path, char ***validPaths, int *stepCount, int *pathCount){
   int i;
   char** newPath;
   newPath = (char**) malloc(sizeof(char*) * (*stepCount) + 8);
   i = 0;
   while(i < (*stepCount)){
      newPath[i] = path[i]->name;
      i++;
   }
   newPath[i] = NULL;
   if (*pathCount != 0) {
      i = 0;
      while(i < (*pathCount) - 1){
         if(comparePaths(newPath, validPaths[i]) == 1){
            free(newPath);
           return;
      }
      i++;
      }
   }
   validPaths[(*pathCount)++] = newPath;
   validPaths[(*pathCount)] = NULL;
}