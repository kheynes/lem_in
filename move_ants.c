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

void	moveAnts(char ***bestPaths, int antCount, int likelyPaths){
    ant    *antList[antCount];
    int    antsInPath[likelyPaths];
    char   *alreadymoved[antCount];
   

    int i = 0;
    int y = 0;
    int ant = 1;
    while(i < likelyPaths){
        antsInPath[i++] = 0;
    }
    i = 0;
    while (ant <= antCount) {
        y = findPathToUse(bestPaths, likelyPaths - 1, antsInPath);
        addAnt(antList, ant, bestPaths[y], &i);
        antsInPath[y] = antsInPath[y] + 1;
        ant++;
    }
    ft_putchar('\n');
    while(1){
        i = 0;
        clearMoved(alreadymoved, antCount);
        while(i < antCount){
            if(antList[i]->pos == pathLength(antList[i]->path)){
                i++;
                continue;
            }
            if(!(occupied(alreadymoved, antList[i]->path[antList[i]->pos], antCount)) || antList[i]->pos == pathLength(antList[i]->path) - 1){
                print_move(antList[i]->name, antList[i]->path[antList[i]->pos]);
                alreadymoved[i] = antList[i]->path[antList[i]->pos];
                antList[i]->pos = antList[i]->pos + 1;
                i++;
            } else {
                i++;
            }
            if (i == antCount){
                if(antList[i - 1]->pos == pathLength(antList[i - 1]->path)){
                    ft_putchar('\n');
                    freeAnts(antList, antCount);
                    return;
                }
            }
        }
        ft_putchar('\n');
    }
}

void    clearMoved(char **moved, int count){
    int i = 0;
    while(i < count){
        moved[i++] = NULL;
    }
}

int     occupied(char **moved, char *step, int count){
    int i = 0;
    while(i < count){
        if(moved[i] == NULL){
            i++;
           continue;
        }
        if(ft_strcmp(moved[i], step) == 0){
            return 1;
        }
        i++;
    }
    return 0;
}

void    print_move(int ant, char *step){
        ft_putchar('L');
        ft_putnbr(ant);
        ft_putchar('-');
        ft_putstr(step);
        ft_putchar(' ');
}

void    addAnt(ant **antList, int name, char **path, int *antCount){
    ant *newAnt;
    newAnt = (ant*)malloc(sizeof(ant));
    newAnt->name = name;
    newAnt->path = path;
    newAnt->pos = 1;
    antList[(*antCount)++] = newAnt;

}

void    freeAnts(ant **antList, int antCount){
    int i = 0;
    while(i < antCount){
        free(antList[i++]);
    }
}