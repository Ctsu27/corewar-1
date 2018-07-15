/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:34:11 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:34:13 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ke_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	c = (char)c;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
