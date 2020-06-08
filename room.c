/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:03:41 by kheynes           #+#    #+#             */
/*   Updated: 2020/05/31 21:03:41 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void        make_room_list(t_room **room, char *line, int roomType)
{
    char	**input;
	char	*name;
	int		x;
	int		y;

	input = ft_strsplit(line, ' ');
	name = input[0];
	x = ft_atoi(input[1]);
	y = ft_atoi(input[2]);
	push(room, name, x, y, roomType);
}

int		is_comment(char *line)
{
	int		type;

	type = 0;

	if(ft_strequ(line, "##start"))
		type = 1;
	else if(ft_strequ(line, "##end"))
		type = 2;
	else
		type = 0;

	return type;
}