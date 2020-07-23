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

int	read_input(room **roomList, r_link** links)
{
	char	*line;
	int		antCount;
	int		type;
	char    **input;
	int 	i;

	antCount = 0;
	type = 0;
	
	while((get_next_line(0, &line)) > 0)
	{	
		if (line[0] == '#' || line[0] == 'L')
		{
			if(line[1] == '#'){
				type = is_comment(line);
			}
			ft_putendl(line);
			free(line);
			continue;
		}
		else
		{
			if (antCount == 0)
			{
				antCount = has_ants(line);
				if (!antCount)
				{
					free(line);
					exit(1);
				}
				else 
				{
					ft_putendl(line);
					free(line);
					continue;
				}
			}	

			if (is_room_link(line))
			{
				make_links_list(links, line, roomList);
			}
			else
			{
				input = ft_strsplit(line, ' ');
				if(!validInput(input)){
					i = 0;
					while(input[i]){
						free(input[i++]);
					}
					free(input);
					free(line);
					freeRoomList(roomList);
					free_links(links);
					exit(1);
				}
				add_room(roomList, input[0], type);
				type = 0;
				i = 0;
				while(input[i]){
					free(input[i++]);
				}
				free(input);
			}
		}
		ft_putendl(line);
		free(line);
	}
	reverse(roomList);
	return antCount;
}

int	validInput(char **str){
	int i = 0;
	if(str[i]){
		i++;
		while(str[i]){
			if(is_integer(str[i]) == 0){
				ft_putendl("\033[0;31mError: Empty/invalid line(s)\033[0m");
				return 0;
			}
			i++;
		}
	} else {
		ft_putendl("\033[0;31mError: Empty/invalid line(s)\033[0m");
		return 0;
	}
	if (i != 3){
		ft_putendl("\033[0;31mError: Empty/invalid line(s)\033[0m");
		return 0;
	}
	return 1;
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

int	includes_start_end(room *roomList)
{
	int		roomCount;
	roomCount = 0;

	while(roomList){
		roomCount += roomList->type;
		roomList = roomList->next;
	}

	if (roomCount != 3)
	{
		ft_putendl("\033[0;31mError: No Start/End room\033[0m");
		return 0;
	}
	return 1;
}

int		has_ants(char *line)
{
	int		ants;

	ants = 0;
	if(is_integer(line))
		ants = ft_atoi(line);
	
	if(ants > 0)
	{
		if(ants > 500000)
		{
			ft_putendl("\033[0;31mError: Number of ants must be less than 500,000\033[0m");
			return 0;
		}
		return ants;
	}
		
	else
	{
		ft_putendl("\033[0;31mError: No ants\033[0m");
		return 0;
	}
	return 1;
}

int	has_room(room *roomList)
{
	if(roomList == NULL)
	{
		ft_putendl("\033[0;31mError: No rooms\033[0m");
		return 0;
	}
	return 1;
}

int	validPathCheck(char ***validPaths){
	if(!(validPaths[0]))
	{
		ft_putendl("\033[0;31mError: No valid solution\033[0m");
		return 0;
	}
	return 1;
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