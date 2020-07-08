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

int bfs(room* roomList, r_link* links, char ***validPaths) {
   room *stack[MAX];
   room *shortestPath[MAX];
   int stepCount = 0;
   int pathCount = 0;
   char adjMatrix[MAX][MAX];
   int ret;
   buildMatrix(adjMatrix, roomList, links);
   
   ret = breadthFirstSearch(adjMatrix, roomList, stack, shortestPath, &stepCount);
   while(ret){
       addToValidPaths(shortestPath, validPaths, &stepCount, &pathCount);
       while(stepCount){
           pop(stack, &stepCount);
       }
       reset_rooms(&roomList);
      ret = breadthFirstSearch(adjMatrix, roomList, stack, shortestPath, &stepCount);
   }
   return pathCount;
}

int breadthFirstSearch(char adjMatrix[MAX][MAX], room* roomList, room **stack, room **shortestPath, int *stepCount){
   int distance = 0;
   int i = 0;
   room *unvisitedRoom = NULL;
   room *end = NULL;
   room *start = findStart(roomList);
   start->dist = distance++;
   push(stack, start, stepCount);
    while(i < *stepCount){
        start = stack[i++];
        unvisitedRoom = getNextRoom(adjMatrix, start, roomList);
        while (unvisitedRoom != NULL){
            unvisitedRoom->prev = start;
            unvisitedRoom->dist = distance++;
            push(stack, unvisitedRoom, stepCount);
            unvisitedRoom = getNextRoom(adjMatrix, start, roomList);
        }
    }
    i--;
    while(i > 0){
        if(stack[i]->type == 2){
            end = stack[i];
        }
        i--;
    }
    if (end == NULL){
        return 0;
    }
    i = 0;
    
    while(end){
        shortestPath[i++] = end;
        if(end->prev == NULL){
            break;
        }
        removeFromMatrix(end->index, end->prev->index, adjMatrix);
        end = end->prev;
    }
    reverse_path(shortestPath, i);
    return 1;
}

void reverse_path(room **shortestPath, int len){
    int high = len - 1;
    int low = 0;
    room *temp;
    while(low < high){
        temp = shortestPath[low];
        shortestPath[low] = shortestPath[high];
        shortestPath[high] = temp;
        high--;
        low++;
    }
    shortestPath[len] = NULL;
}