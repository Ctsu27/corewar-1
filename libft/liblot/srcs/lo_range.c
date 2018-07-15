/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:08:20 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:54 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*lo_range(int min, int max)
{
	int i;
	int size;
	int *array;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	if (!(array = (int*)malloc(sizeof(int) * ((unsigned long)size))))
		return (0);
	lo_bzero(array, sizeof(int) * ((unsigned long)size));
	while (i < size)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}
