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

void	includes_start_end(t_room** head)
{
	t_room*		temp;
	int			roomCount;

	temp = *head;
	roomCount = 0;

	while(temp != NULL)
	{
		roomCount += temp->roomType;
		temp = temp->next;
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

void	has_room(t_room* rooms)
{
	if(size(&rooms) == 0)
	{
		ft_putendl("\033[0;31mError: No rooms\033[0m");
		exit(1);
	}
}