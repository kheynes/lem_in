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

