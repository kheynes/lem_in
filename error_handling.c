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