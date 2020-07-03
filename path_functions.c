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

int pathLength(char **step){
   int i = 0;
   while(step[i]){
      i++;
   }
   return i;
}

void printPath(char** path){
  int i = 0;
  while(path[i + 1] != NULL){
     ft_putstr(path[i++]);
     ft_putstr("->");
  }
   ft_putstr(path[i]);
   ft_putstr("\n");
}

void  printAllPaths(char ***paths){
   int x = 0;
   while(paths[x]){
      printPath(paths[x]);
      ft_putstr("\n");
      x++;
   	}
}

void freeAllPaths(char ***validPaths){
   int x = 0;
	while(validPaths[x]){
      free(validPaths[x]);
      x++;
   	}
}

void  sortPaths(char ***paths){
   int i = 0;
   int j = 0;
   char **temp;

   while(paths[i]){
      j = i + 1;
      while(paths[j]){
         if(pathLength(paths[i]) > pathLength(paths[j])){
            temp = paths[i];
            paths[i] = paths[j];
            paths[j] = temp;
         }
         j++;
      }
      i++;
   }
}

char **findNextPath(char **path, char ***validPaths, int ants){
   int i = 1;
   while (validPaths[i]){
      if(comparePaths(path, validPaths[i], ants) < 0){
           return validPaths[i];
      }
      i++;
   }
   return NULL;
}

int comparePaths(char **path1, char **path2, int n){
   int i = 1;
   while(i < n){
      if (ft_strcmp(path1[i], path2[i]) == 0 && path1[i + 1] != NULL){
            return 1;
      }
      i++;
   }
   return -1;
}