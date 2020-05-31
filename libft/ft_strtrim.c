/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:15:18 by kheynes           #+#    #+#             */
/*   Updated: 2019/06/12 13:45:16 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t j;
	size_t n;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	j = ft_strlen(s);
	while (i < j && (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n'))
		j--;
	if (i == j)
		return (ft_strnew(1));
	n = j - i;
	return (ft_strsub(s, i, n));
}
