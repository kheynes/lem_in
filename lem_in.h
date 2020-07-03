/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 12:14:01 by kheynes           #+#    #+#             */
/*   Updated: 2020/05/31 12:14:01 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define MAX 100
typedef struct          s_room
{
	char name[10];
   	int visited;
   	int type; //1=start, 2=end
	struct s_room		*next;
}                       room;

typedef struct			s_link
{
	char				*roomA;
	char				*roomB;
	struct s_link		*next;
}						r_link;

// typedef struct			s_ant
// {
// 	int					antNum;
// 	struct s_ant		*next;
// }						t_ant;


int			is_integer(char *str);
void		includes_start_end(room **roomList);
int			is_comment(char *line);
int			has_ants(char *line);
void		has_room(room** roomList);
int			read_input(room** roomList, r_link **links);

/** Links **/

int			is_room_link(char *line);
int			array_len(char **rooms);
void		make_links_list(r_link **r_link, char *line);
r_link*		newLink(char *roomA, char *roomB);
void		push_link(r_link** root, char *roomA, char *roomB);
void		print_links(r_link *head);
int			size_link(r_link **root);
void		free_links(r_link **links);

/**PathFinder**/
void 		addRoom(room **roomList, char *name, int type, int *roomCount);
int 		findPos(room** roomList, char *name);
void 		initMatrix(int adjMatrix[MAX][MAX]);
void 		buildMatrix(int adjMatrix[MAX][MAX], room** roomList, r_link* links);
int 		findStart(room** roomList);
void 		pushStack(int *stack, int *top, int item);
int 		pop(int *stack, int *top);
int 		getNextUnvisitedRoom(int adjMatrix[MAX][MAX], int roomIndex, room** roomList, int num);
int 		getNumOfAdjRooms(int adjMatrix[MAX][MAX], int roomIndex, room** roomList);
void 		addToPotentialPath(room **potentialPath, room *step, int *stepCount);
void 		removeFromPotentialPath(room **potentialPath, int *stepCount);
int 		pathLength(char **step);
void 		addToValidPaths(room **path, char ***validPaths, int *stepCount, int *pathCount);
int			depthFirstSearch(room** roomList, r_link* links, char ***validPaths);
void 		findAllPathsUtil(int adjMatrix[MAX][MAX], int start, room** roomList, room **potentialPath, int *stepCount, char ***validPaths, int *pathCount, int *stack, int *top);
void 		printPath(char** path); 
void  		printAllPaths(char ***validPaths);
void 		freeRoomList(room **roomList);
void 		freeAllPaths(char ***validPaths);
char		**findShortestPath(char ***paths);
void  		sortPaths(char ***paths);
void		moveAnts(char ***validPaths, int antCount, int likelyPaths);
char 		**findNextPath(char **path, char ***validPaths, int ants);
int 		comparePaths(char **path1, char **path2, int n);
#endif