/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:22:30 by kheynes           #+#    #+#             */
/*   Updated: 2020/07/02 21:22:30 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*get_roomtype(t_room **head, int roomType)
{
	t_room		*temp;
 
	temp = *head;
	while (temp && temp->roomType != roomType)
	{
		temp = temp->next;
	}
	return(temp);
}

t_room		*get_roomname(t_room **head, char *name)
{
	t_room		*temp;
 
	temp = *head;
	while (temp && !(ft_strequ(temp->name, name)))
	{
		temp = temp->next;
	}
	return(temp);
}

void		find_path(t_room **room)
{
	t_room		*temp;
	int			i;

	temp = get_roomtype(room, 2);
	i = 0;

	temp->value = size(room);
	while(i < array_len(temp->linked_rooms))
	{
		assign_value(room, temp->linked_rooms[i++], temp->value - 1);
	}
}

void		assign_value(t_room **room, char *name, int value)
{
	t_room		*temp;
	int			i;

	temp = get_roomname(room, name);
	i = 0;

	if (temp->value < value)
	{
		temp->value = value;
		while(i < array_len(temp->linked_rooms))
		{
			assign_value(room, temp->linked_rooms[i++], temp->value - 1);
		}
	}
}

t_room		*highest_value(t_room **head, char **linked_rooms)
{
	t_room		*temp;
	t_room		*highest;
	int			i;

	i = 0;
	highest = get_roomname(head, linked_rooms[i]);

	while(i < array_len(linked_rooms))
	{
		temp = get_roomname(head, linked_rooms[i]);
		if (temp->value > highest->value)
			highest = temp;
		i++;
	} 
	return(highest);
}