/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:25:13 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:56 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strchr(char *s, int c)
{
	if (!(s))
		return (NULL);
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char*)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	return (0);
}
