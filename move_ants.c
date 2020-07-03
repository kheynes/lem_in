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

void	moveAnts(char ***validPaths, int antCount, int likelyPaths){
	char **pathsToUse[antCount];
    int i = 0;
    pathsToUse[i] = validPaths[i];
    while(++i < likelyPaths){
        pathsToUse[i] = findNextPath(pathsToUse[i - 1], validPaths, antCount);
    }
    i = 0;
    while (i < likelyPaths){
        printPath(pathsToUse[i++]);
    }
}
