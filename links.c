/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:29:20 by kheynes           #+#    #+#             */
/*   Updated: 2020/06/23 11:29:20 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	make_links_list(r_link **links, char *line)
{
	char	**input;
	char	*roomA;
	char	*roomB;

	input = ft_strsplit(line, '-');
	roomA = input[0];
	roomB = input[1];
	push_link(links, roomA, roomB);
	free(input);
	
}

void	free_links(r_link **links){
	r_link	*current = *links;
	r_link	*next;
	while (current != NULL){
		next = current->next;
		free(current->roomA);
		free(current->roomB);
		free(current);
		current = next;
	}
	*links = NULL;
}