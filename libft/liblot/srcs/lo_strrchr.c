/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:28:00 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:02 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strrchr(char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = lo_strlen(s);
	if (c != '\0')
		i--;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i--;
	}
	return (0);
}
