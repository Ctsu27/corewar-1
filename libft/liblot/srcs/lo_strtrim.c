/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:14:02 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:04 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strtrim(char const *s)
{
	int		start;
	int		end;
	int		k;
	char	*ptr;

	if (!(s))
		return (NULL);
	start = 0;
	while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
	{
		start++;
	}
	k = start;
	end = start;
	while (s[k])
	{
		if (s[k] != '\t' && s[k] != '\n' && s[k] != ' ' && s[k] != '\0')
			end = k;
		k++;
	}
	ptr = lo_strsub(s, (unsigned int)start, (size_t)(end - start + 1));
	return (ptr);
}
