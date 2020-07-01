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

typedef struct          s_room
{
	char                *name;
	int                 x;
	int                 y;
	int					roomType;
	char				**linked_rooms;
	struct s_room       *next;
}                       t_room;

typedef struct			s_link
{
	char				*roomA;
	char				*roomB;
	struct s_link		*next;
}						t_link;

// typedef struct			s_ant
// {
// 	int					antNum;
// 	struct s_ant		*next;
// }						t_ant;

void        make_room_list(t_room **room, char *line, int roomType);
t_room*     newNode(char *name, int x, int y, int roomType);
void        push(t_room** root, char *name, int x, int y, int roomType);
void        print_room(t_room *head);
int			size(t_room **root);
int			is_integer(char *str);
void		includes_start_end(t_room** head);
int			is_comment(char *line);
int			has_ants(char *line);
void		has_room(t_room* rooms);
void		read_input(t_room** room, t_link** link);
void		array_init(t_room **root);

/** Links **/

int			is_room_link(char *line);
int			array_len(char **rooms);
void		make_links_list(t_link **link, char *line);
t_link*		newLink(char *roomA, char *roomB);
void		push_link(t_link** root, char *roomA, char *roomB);
void		print_links(t_link *head);
int			size_link(t_link **root);
void		link_rooms(t_room **head, t_link **links);
void		rev_link_rooms(t_room **head, t_link **links);

/** Testing **/
void		print_map(t_room **rooms);

#endif