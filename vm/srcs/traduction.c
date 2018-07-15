/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traduction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:22:44 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/25 19:23:43 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		ft_filler(unsigned char i, int j)
{
	while (i >= 1)
	{
		i /= 16;
		j++;
	}
	return (j);
}

char			*traduction(unsigned char n)
{
	int					j;
	char				*ptr;
	char				*converter;

	converter = "0123456789abcdef";
	if (n > 15)
		j = 0;
	else if (n == 0)
		j = 2;
	else
		j = 1;
	j = ft_filler(n, j);
	if (!(ptr = lo_strnew((size_t)j)))
		return (NULL);
	j--;
	while (j >= 0)
	{
		ptr[j] = converter[n % 16];
		n /= 16;
		j--;
	}
	return (ptr);
}
