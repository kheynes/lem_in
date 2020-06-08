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
	int			antCount;
	int			type;

	room = NULL;
	antCount = 0;
	type = 0;

	while((get_next_line(0, line)) > 0)
	{
		ft_putendl(*line);
		if ((*line)[0] == '#' || (*line)[0] == 'L')
		{
			if(ft_strequ(*line, "##start"))
				type = 1;
			else if(ft_strequ(*line, "##end"))
				type = 2;
			else
				type = 0;
			continue;
		}
		if (antCount == 0)
		{
			if(is_integer(*line))
				antCount = ft_atoi(*line);
			else
			{
				ft_putendl("\033[0;31mError: No ants\033[0m");
				exit(1);
			}
		}
		else
		{
			make_room_list(&room, *line, type);
			type = 0;
		}
	}

	if(size(&room) == 0)
	{
		ft_putendl("\033[0;31mError: No rooms\033[0m");
		exit(1);
	}

	includes_start_end(&room);
	
	print_room(room);

	return(0);
}