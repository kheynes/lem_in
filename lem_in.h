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
# define MAX 700

typedef struct          s_room
{
	char name[10];
   	int visited;
   	int type; //1=start, 2=end
	struct s_room *next;
}                       room;

typedef struct			s_link
{
	char				*roomA;
	char				*roomB;
	struct s_link		*next;
}						r_link;

typedef struct			s_ant
{
	int					name;
	char				**path;
	int					pos;
}						ant;

/**error_handling**/
int			read_input(room** roomList, r_link **links);
int 		validInput(char **str);
int			is_integer(char *str);
int			includes_start_end(room *roomList);
int			is_comment(char *line);
int			has_ants(char *line);
int			has_room(room* roomList);
int			is_room_link(char *line);
int			validPathCheck(char ***validPaths);
/**link_functions**/
r_link*		newLink(char *roomA, char *roomB);
void		push_link(r_link** root, char *roomA, char *roomB);
void		print_links(r_link *head);
int			size_link(r_link **root);
/** links **/
void		make_links_list(r_link **r_link, char *line);
void		free_links(r_link **links);
/**room**/
room*		newRoom(char *name, int type);
void 		add_room(room **roomList, char *name, int type);
void 		reverse(room **roomList);
void		print_rooms(room *head);
void 		freeRoomList(room **roomList);
/**pathFinder**/
int			depthFirstSearch(room* roomList, r_link* links, char ***validPaths);
void 		findAllPathsUtil(int adjMatrix[MAX][MAX], room *start, room* roomList, room **potentialPath, int *stepCount, char ***validPaths, int *pathCount, room **stack, int *top);
room* 		getNextUnvisitedRoom(int adjMatrix[MAX][MAX], room *start, room *roomList, int num);
int 		getNumOfAdjRooms(int adjMatrix[MAX][MAX], room *start, room *roomList);
void 		addToPotentialPath(room **potentialPath, room *step, int *stepCount);
void 		removeFromPotentialPath(room **potentialPath, int *stepCount);
void 		addToValidPaths(room **path, char ***validPaths, int *stepCount, int *pathCount);
/**pathFinder_helpers**/
void 		buildMatrix(int adjMatrix[MAX][MAX], room* roomList, r_link* links);
void 		initMatrix(int adjMatrix[MAX][MAX]);
int 		findPos(room* roomList, char *name);
room* 		findStart(room* roomList);
void 		pushStack(room **stack, int *top, room *item);
room* 		pop(room **stack, int *top);
/**path_functions**/
int 		pathLength(char **step);
void 		printPath(char** path); 
void  		printAllPaths(char ***validPaths);
void 		freeAllPaths(char ***validPaths);
char		**findShortestPath(char ***paths);
void  		sortPaths(char ***paths);
char 		**findNextPath(char **path, char ***validPaths);
int 		comparePaths(char **path1, char **path2);
/**move_ants**/
void		moveAnts(char ***validPaths, int antCount, int likelyPaths);
int     	findPathToUse(char ***paths, int n, int *antsInPath);
void    	print_move(int ant, char *step);
void    	addAnt(ant **antList, int name, char **path, int *antCount);
int     	occupied(char **moved, char *step, int count);
void    	clearMoved(char **moved, int count);
void    	freeAnts(ant **antList, int antCount);
#endif