/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:35:30 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:35:32 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ke_strncat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < len)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
