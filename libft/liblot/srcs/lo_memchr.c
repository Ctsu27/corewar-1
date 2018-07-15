/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:23:28 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:49 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*lo_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!(s))
		return (NULL);
	ptr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((unsigned char*)s + i);
		i++;
	}
	return (NULL);
}
