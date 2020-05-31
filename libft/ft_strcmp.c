/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kheynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 08:45:54 by kheynes           #+#    #+#             */
/*   Updated: 2019/06/19 13:17:45 by kheynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 < (unsigned char)*s2)
		return (-1);
	else if ((unsigned char)*s1 > (unsigned char)*s2)
		return (1);
	else
		return (0);
}
