/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:51:15 by kheynes           #+#    #+#             */
/*   Updated: 2020/05/31 20:51:15 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room*    newNode(char *name, int x, int y)
{
	t_room*    roomNode;

	roomNode = (t_room*)malloc(sizeof(t_room));
	roomNode->name = name;
	roomNode->x = x;
	roomNode->y = y;
	roomNode->next = NULL;
	return roomNode;
}

void        push(t_room** root, char *name, int x, int y)
{
	t_room*    roomNode;

	roomNode = newNode(name, x, y);
	roomNode->next = *root;
	*root = roomNode;
}

// int         pop(t_room** root)
// {
//     t_room*    temp;
//     int         popped;

//     temp = *root;
//     *root = (*root)->next;
//     popped = temp->data;
//     free(temp);

//     return popped;
// }

int		size(t_room **root)
{
	int			i;
	t_room*		temp;

	i = 0;
	temp = *root;
	
	while(temp)
	{
		i++;
		temp = temp->next;
	}
	return(i);
}

// void        free_room(t_room** room)
// {
//     while(size(room) > 0)
//     {
//         pop(room);
//     }
// }

void        print_room(t_room *head)
{
	t_room      *temp;

	temp = head;

	while(temp)
	{
		ft_putstr(temp->name);
		ft_putstr(" ");
		ft_putnbr(temp->x);
		ft_putstr(" ");
		ft_putnbr(temp->y);
		ft_putstr("\n");
		temp = temp->next;
	}
}