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

void	read_input(t_room** room)
{
	char	*line[1];
	int		antCount;
	int		type;

	antCount = 0;
	type = 0;

	while((get_next_line(0, line)) > 0)
	{
		ft_putendl(*line);
		if ((*line)[0] == '#' || (*line)[0] == 'L')
		{
			type = is_comment(*line);
			continue;
		}
		if (antCount == 0)
			antCount = has_ants(*line);
		else
		{
			make_room_list(room, *line, type);
			type = 0;
		}
	}
}

int     main()
{
	t_room		*room;

	room = NULL;

	read_input(&room);
	has_room(room);
	includes_start_end(&room);
	print_room(room);

	return(0);
}