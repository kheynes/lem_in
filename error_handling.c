/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:39:31 by kheynes           #+#    #+#             */
/*   Updated: 2020/06/01 17:39:31 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	read_input(room **roomList, r_link** links)
{
	char	*line;
	int		antCount;
	int 	roomCount;
	int		type;
	char    **input;

	roomCount  = 0;
	antCount = 0;
	type = 0;

	while((get_next_line(0, &line)) > 0)
	{
		ft_putendl(line);
		if (line[0] == '#' || line[0] == 'L')
		{
			type = is_comment(line);
			continue;
		}
		if (antCount == 0)
			antCount = has_ants(line);
		else
		{
			if (is_room_link(line))
			{
				make_links_list(links, line);
			}
			else if(size_link(links) == 0)
			{
				input = ft_strsplit(line, ' ');
				addRoom(roomList, input[0], type, &roomCount);
				type = 0;
				int i = 0;
				while(input[i]){
					free(input[i++]);
				}
				free(input);
			}
		}
		free(line);
	}
	return antCount;
}

int		is_integer(char *str)
{
	char    *arr;
	char    *temp;
	int		i;
	int  	result; 
	
	arr = str;
	i = ft_atoi(arr);
	temp = ft_itoa(i);
  
	if (ft_strequ(temp, arr))
		result = 1;
	else
		result = 0;
	free(temp);
	return result;
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

void	includes_start_end(room** roomList)
{
	int		roomCount;
	int		i;
	i = 0;
	roomCount = 0;

	while(roomList[i])
	{
		roomCount += roomList[i]->type;
		i++;
	}

	if (roomCount != 3)
	{
		ft_putendl("\033[0;31mError: No Start/End room\033[0m");
		exit(1);
	}
}

int		has_ants(char *line)
{
	if(is_integer(line))
		return (ft_atoi(line));
	else
	{
		ft_putendl("\033[0;31mError: No ants\033[0m");
		exit(1);
	}
}

void	has_room(room** roomList)
{
	if(!(roomList[0]))
	{
		ft_putendl("\033[0;31mError: No rooms\033[0m");
		exit(1);
	}
}

int		is_room_link(char *line)
{
	int i = 0;
	while (line[i++]){
		if (line[i] == '-' && i != 0){
			return 1;
		}
	}
	return 0;
}