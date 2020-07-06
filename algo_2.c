/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:50:51 by kheynes           #+#    #+#             */
/*   Updated: 2020/07/06 20:50:51 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void        follow_path(t_room **room)
{
    t_room      *temp;

    temp = get_roomtype(room, 1);
	ft_putendl(temp->name);
	while(temp->roomType != 2)
	{
		temp = highest_value(room, temp->linked_rooms);
		ft_putendl(temp->name);
	}
}