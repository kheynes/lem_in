/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 12:16:37 by kheynes           #+#    #+#             */
/*   Updated: 2020/05/31 12:16:37 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     main()
{
	char		*line[1];
	t_room		*room;

	while((get_next_line(0, line)) > 0)
	{
		if ((*line)[0] == '#' || (*line)[0] == 'L')
			continue;
		ft_putendl(*line);
		make_room_list(&room, line);
	}

	print_room(room);

	return(0);
}