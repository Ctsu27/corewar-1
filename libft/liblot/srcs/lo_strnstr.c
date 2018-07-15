/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:27:44 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:02 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strnstr(char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	if (!haystack)
		return (NULL);
	if (!(needle[0]) || !needle)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && (i < len))
	{
		k = i;
		while (haystack[i] == needle[j] && (i < len))
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char*)haystack + k);
		}
		j = 0;
		i = k;
		i++;
	}
	return (0);
}
