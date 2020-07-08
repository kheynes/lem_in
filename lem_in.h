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
# define MAX 1002

typedef struct          s_room
{
	char name[10];
   	int visited;
   	int type; //1=start, 2=end
	int index;
	int dist;
	struct s_room *prev;
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
void		make_links_list(r_link **r_link, char *line, room **roomList);
void		free_links(r_link **links);
/**room**/
room*		newRoom(char *name, int type);
void 		add_room(room **roomList, char *name, int type);
void 		reverse(room **roomList);
void		print_rooms(room *head);
void 		freeRoomList(room **roomList);
void 		reset_rooms(room **roomList);
/**bfs**/
int 		bfs(room* roomList, r_link* links, char ***validPaths);
int 		breadthFirstSearch(char adjMatrix[MAX][MAX], room* roomList, room **potentialPath, room **shortestPath, int *stepCount);
void 		reverse_path(room **shortestPath, int len);

/**pathFinder_helpers**/
void 		buildMatrix(char adjMatrix[MAX][MAX], room* roomList, r_link* links);
void 		initMatrix(char adjMatrix[MAX][MAX]);
void  		removeFromMatrix(int room1, int room2, char adjMatrix[MAX][MAX]);
int 		findPos(room* roomList, char *name);
room* 		findStart(room* roomList);
room*		getNextRoom(char adjMatrix[MAX][MAX], room *start, room *roomList);
void 		push(room **potentialPath, room *step, int *stepCount);
void 		pop(room **potentialPath, int *stepCount);
void 		addToValidPaths(room **path, char ***validPaths, int *stepCount, int *pathCount);

/**path_functions**/
int 		pathLength(char **step);
void 		printPath(char** path); 
void  		printAllPaths(char ***validPaths);
void 		freeAllPaths(char ***validPaths);
char		**findShortestPath(char ***paths);
void  		sortPaths(char ***paths);
int 		comparePaths(room **path1, char **path2);
/**move_ants**/
void		moveAnts(char ***bestPaths, int antCount);
int     	findPathToUse(char ***paths, int n, int *antsInPath);
void    	print_move(int ant, char *step);
void    	addAnt(ant **antList, int name, char **path, int *antCount);
int     	occupied(char **moved, char *step, int count);
void    	clearMoved(char **moved, int count);
void    	freeAnts(ant **antList, int antCount);
#endif