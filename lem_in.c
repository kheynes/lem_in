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

void	read_input(t_room** room, t_link** link)
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
			if (is_room_link(*line))
			{
				make_links_list(link, *line);
			}
			else if(size_link(link) == 0)
			{
				make_room_list(room, *line, type);
				type = 0;
			}
		}
	}
}

int     main()
{
	t_room		*room;
	t_link		*link;

	room = NULL;
	link = NULL;

	read_input(&room, &link);
	has_room(room);
	includes_start_end(&room);
	ft_putendl("####################");
	print_links(link);
	ft_putendl("####################");
	array_init(&room);
	link_rooms(&room, &link);
	ft_putstr("\n");
	rev_link_rooms(&room, &link);
	print_map(&room);
	ft_putendl("####################");
	find_path(&room);
	print_room(room);

	return(0);
}

void print_map(t_room **rooms)
{
    t_room *temp;
    
    temp= *rooms;
    
    while(temp){
        int i = 0;
        ft_putstr("\nRooms linked to room => ");
        ft_putendl(temp->name);
        while(i < array_len(temp->linked_rooms)){
            ft_putendl(temp->linked_rooms[i]);
            i++;
        }
        temp= temp->next;
    }
}