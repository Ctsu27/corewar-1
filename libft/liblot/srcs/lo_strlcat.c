/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:26:15 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:00 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		lo_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	k;

	if (!dst || !src)
		return (0);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	k = i + (size_t)j;
	if (size < i)
		k = size + (size_t)j;
	j = 0;
	while (src[j] != '\0' && i < size - 1 && size != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k);
}
