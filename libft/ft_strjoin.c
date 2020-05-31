/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:45:44 by kheynes           #+#    #+#             */
/*   Updated: 2019/06/21 11:10:31 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!fresh)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		fresh[j++] = s1[i++];
	i = 0;
	while (s2[i])
		fresh[j++] = s2[i++];
	return (fresh);
}
