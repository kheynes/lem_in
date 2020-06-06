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
	struct s_room       *next;
}                       t_room;

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

#endif