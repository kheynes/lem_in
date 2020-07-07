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
   char *potentialPath[MAX];
   int stepCount = 0;
   int pathCount = 0;
   room *start = findStart(roomList);
   int stack[MAX]; 
   int top = -1; 
   char adjMatrix[MAX][MAX];
   buildMatrix(adjMatrix, roomList, links);
   findAllPathsUtil(adjMatrix, start, roomList, potentialPath, &stepCount, validPaths, &pathCount, stack, &top);
   sortPaths(validPaths);
   return (getNumOfAdjRooms(adjMatrix, start, roomList));
}

void findAllPathsUtil(char adjMatrix[MAX][MAX], room *start, room* roomList, char **potentialPath, int *stepCount, char ***validPaths, int *pathCount, int *stack, int *top){
   int adjRooms;
   int index;
   room *unvisitedRoom = NULL;
   addToPotentialPath(potentialPath, start, stepCount);
   index = findPos(roomList, start->name);
   pushStack(stack, top, index);
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
   pop(stack, top, roomList)->visited = 0;
}

int getNumOfAdjRooms(char adjMatrix[MAX][MAX], room *start, room *roomList){
   int i = 0;
   int num = 0;
   int roomIndex;
   roomIndex = findPos(roomList, start->name);
   while(roomList){
      if(adjMatrix[roomIndex][i] == '1' && roomList->visited == 0) {
        num++;
      }
      i++; 
      roomList = roomList->next;
   }
   return num;
}
room *getNextUnvisitedRoom(char adjMatrix[MAX][MAX], room *start, room *roomList, int num) {
   int i = 0;
   int roomIndex;
   roomIndex = findPos(roomList, start->name);
   while(roomList) {
      if(adjMatrix[roomIndex][i] == '1' && roomList->visited == 0) {
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

void addToPotentialPath(char **potentialPath, room *step, int *stepCount) {
   potentialPath[(*stepCount)++] = step->name;
}

void removeFromPotentialPath(char **potentialPath, int *stepCount) {
   potentialPath[(*stepCount) - 1] = NULL;
   (*stepCount)--;
}

void addToValidPaths(char **path, char ***validPaths, int *stepCount, int *pathCount){
   int i;
   if (*pathCount != 0) {
      i = 0;
      while(i < (*pathCount) - 1){
         if(comparePaths(path, validPaths[i]) == 1){
           return;
      }
      i++;
      }
   }
   char** newPath;
   newPath = (char**) malloc(sizeof(char*) * (*stepCount) + 8);
   i = 0;
   while(i < (*stepCount)){
      newPath[i] = path[i];
      i++;
   }
   newPath[i] = NULL;
   validPaths[(*pathCount)++] = newPath;
   validPaths[(*pathCount)] = NULL;
}