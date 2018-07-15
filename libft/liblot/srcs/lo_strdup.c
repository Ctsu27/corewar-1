/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:25:57 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:58 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strdup(const char *s1)
{
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	i = lo_strlen(s1);
	if (!(s2 = (char*)lo_memalloc(sizeof(char) * ((unsigned long)(1 + i)))))
		return (0);
	s2[i] = '\0';
	--i;
	while (i >= 0)
	{
		s2[i] = s1[i];
		i--;
	}
	return (s2);
}
