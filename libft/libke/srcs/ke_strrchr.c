/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:36:06 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:36:12 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ke_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	c = (char)c;
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i);
		i--;
	}
	return (NULL);
}
