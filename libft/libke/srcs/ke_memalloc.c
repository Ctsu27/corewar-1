/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:30:41 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:30:43 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ke_memalloc(size_t size)
{
	int		*dest;

	dest = NULL;
	dest = (int *)malloc(sizeof(*dest) * size);
	if (dest == NULL)
		return (NULL);
	while (size > 0)
	{
		dest[size - 1] = 0;
		size--;
	}
	return (dest);
}
