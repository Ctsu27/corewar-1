/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:28:13 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:03 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strstr(char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	if (!haystack)
		return (NULL);
	if (!(needle[0]) || !needle)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		k = i;
		while (haystack[i] == needle[j])
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
