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

int depthFirstSearch(room** roomList, r_link* links, char ***validPaths) {
   room *potentialPath[MAX];
   int stepCount = 0; 
   int pathCount = 0;
   int start = findStart(roomList);
   int stack[MAX]; 
   int top = -1; 
   int adjMatrix[MAX][MAX];
   buildMatrix(adjMatrix, roomList, links);
   findAllPathsUtil(adjMatrix, start, roomList, potentialPath, &stepCount, validPaths, &pathCount, stack, &top);
   sortPaths(validPaths);
   return (getNumOfAdjRooms(adjMatrix, start, roomList));
}

void findAllPathsUtil(int adjMatrix[MAX][MAX], int start, room** roomList, room **potentialPath, int *stepCount, char ***validPaths, int *pathCount, int *stack, int *top){
   int adjRooms;
   int unvisitedRoomIndex;
   addToPotentialPath(potentialPath, roomList[start], stepCount);
   pushStack(stack, top, start);
   roomList[start]->visited = 1;

   if (roomList[start]->type == 2) {
      addToValidPaths(potentialPath, validPaths, stepCount, pathCount);
   }
   else {
      adjRooms = getNumOfAdjRooms(adjMatrix, start, roomList);
      while (adjRooms > 0){
         unvisitedRoomIndex = getNextUnvisitedRoom(adjMatrix, start, roomList, adjRooms);
         findAllPathsUtil(adjMatrix, unvisitedRoomIndex, roomList, potentialPath, stepCount, validPaths, pathCount, stack, top);
         adjRooms--;
      }
   }
   removeFromPotentialPath(potentialPath, stepCount);
   roomList[pop(stack, top)]->visited = 0;
}

int getNumOfAdjRooms(int adjMatrix[MAX][MAX], int roomIndex, room** roomList){
   int i = 0;
   int num = 0;
   while(roomList[i]) {
      if(adjMatrix[roomIndex][i] == 1 && roomList[i]->visited == 0) {
        num++;
      }
      i++; 
   }
   return num;
}
int getNextUnvisitedRoom(int adjMatrix[MAX][MAX], int roomIndex, room** roomList, int num) {
   int i = 0;
   while(roomList[i]) {
      if(adjMatrix[roomIndex][i] == 1 && roomList[i]->visited == 0) {
         num--;
         if (num == 0){
            return i;
         }
      }
      i++;
   }
   return -1;
}

void addToPotentialPath(room **potentialPath, room *step, int *stepCount) {
   potentialPath[(*stepCount)++] = step;
}

void removeFromPotentialPath(room **potentialPath, int *stepCount) {
   potentialPath[(*stepCount) - 1] = NULL;
   (*stepCount)--;
}

void addToValidPaths(room **path, char ***validPaths, int *stepCount, int *pathCount){
   char** newPath;
   newPath = (char**) malloc(sizeof(char*) * (*stepCount) + 8);
   int i = 0;
   while(i < (*stepCount)){
      newPath[i] = path[i]->name;
      i++;
   }
   newPath[i] = NULL;
   validPaths[(*pathCount)++] = newPath;
   validPaths[(*pathCount)] = NULL;
}