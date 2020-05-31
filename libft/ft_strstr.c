/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:01:41 by kheynes           #+#    #+#             */
/*   Updated: 2019/06/17 15:56:03 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *a;
	const char *b;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		a = haystack;
		b = needle;
		while (*haystack && *b && *haystack == *b)
		{
			haystack++;
			b++;
		}
		if (!*b)
			return ((char*)a);
		haystack = a + 1;
	}
	return (NULL);
}
