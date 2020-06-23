/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:48:48 by kheynes           #+#    #+#             */
/*   Updated: 2020/06/23 11:48:48 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link*		newLink(char *roomA, char *roomB)
{
	t_link*		linkNode;

	linkNode = (t_link*)malloc(sizeof(t_link));
	linkNode->roomA = roomA;
	linkNode->roomB = roomB;
	linkNode->next = NULL;
	return linkNode;
}

void		push_link(t_link** root, char *roomA, char *roomB)
{
	t_link*		linkNode;

	linkNode = newLink(roomA, roomB);
	linkNode->next = *root;
	*root = linkNode;
}

void		print_links(t_link *head)
{
	t_link		*temp;

	temp = head;

	while(temp)
	{
		ft_putstr(temp->roomA);
		ft_putstr("~");
		ft_putstr(temp->roomB);
		ft_putstr("\n");
		temp = temp->next;
	}
}

int		size_link(t_link **root)
{
	int			i;
	t_link*		temp;

	i = 0;
	temp = *root;
	while(temp)
	{
		i++;
		temp = temp->next;
	}
	return(i);
}