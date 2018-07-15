/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:35:11 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:35:13 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ke_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0)
		return (ke_strlen(src));
	i = 0;
	while (dest[i] != '\0' && i < len)
		i++;
	j = i;
	while (src[i - j] != '\0' && i < len - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (i < len)
		dest[i] = '\0';
	j = j + ke_strlen(src);
	return (j);
}
