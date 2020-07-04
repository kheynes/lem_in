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
	ft_putendl(temp->name);

	temp->value = size(room);
	while(i < array_len(temp->linked_rooms))
	{
		assign_value(room, temp->linked_rooms[i++], temp->value - 1);
	}
}

void		assign_value(t_room **room, char *name, int value)
{
	t_room		*temp;

	temp = get_roomname(room, name);
	temp->value = value;
	ft_putendl(temp->name);
}