/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 09:21:16 by kheynes           #+#    #+#             */
/*   Updated: 2019/05/30 15:30:31 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *tmp;

	tmp = dst;
	while (n--)
	{
		if (*src == '\0')
			*tmp++ = 0;
		else
			*tmp++ = *src++;
	}
	return (dst);
}
