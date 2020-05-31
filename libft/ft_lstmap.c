/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:41:05 by kheynes           #+#    #+#             */
/*   Updated: 2019/06/15 11:41:06 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;

	head = f(lst);
	if (head == NULL)
		return (NULL);
	current = head;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		if (current->next == NULL)
			return (NULL);
		current = current->next;
	}
	return (head);
}
