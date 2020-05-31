/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:32:21 by kheynes           #+#    #+#             */
/*   Updated: 2019/06/05 14:46:32 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t l;

	l = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && len-- >= l)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, l) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
