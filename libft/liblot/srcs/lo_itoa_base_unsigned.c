/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:54:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/29 11:16:02 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*exception(long long n)
{
	char	*ptr;

	if (n == 0)
	{
		if (!(ptr = lo_strnew(1)))
			return (NULL);
		ptr = lo_strcpy(ptr, "0");
		return (ptr);
	}
	return (NULL);
}

static int		lo_filler(unsigned long long i, int j, int base)
{
	while (i >= 1)
	{
		i /= (unsigned long long)base;
		j++;
	}
	return (j);
}

char			*lo_itoa_base_unsigned(unsigned long long n, int base)
{
	int			j;
	char		*ptr;
	char		converter[17];

	lo_strcpy(converter, "0123456789abcdef");
	if (base == 0)
		return (NULL);
	if ((ptr = exception((long long)n)) != NULL)
		return (ptr);
	j = lo_filler(n, 0, base);
	if (!(ptr = lo_strnew((size_t)j)))
		return (NULL);
	j--;
	while (n >= 1)
	{
		ptr[j--] = converter[(n % (unsigned long long)base)];
		n /= (unsigned long long)base;
	}
	return (ptr);
}
