/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:40:21 by kehuang           #+#    #+#             */
/*   Updated: 2018/04/13 13:43:55 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ke_strndup(const char *src, unsigned int size)
{
	unsigned int	i;
	char			*dest;

	dest = NULL;
	if ((dest = (char *)malloc(sizeof(*dest) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
