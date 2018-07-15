/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:06:12 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/29 11:10:43 by kehuang          ###   ########.fr       */
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

static int		lo_filler(unsigned long long i, int j, int base, int neg)
{
	while (i >= 1)
	{
		i /= (unsigned long long)base;
		j++;
	}
	neg == -1 ? j++ : j;
	return (j);
}

char			*lo_itoa_base(long long n, int base)
{
	int					j;
	char				*ptr;
	int					neg;
	static char			converter[17] = "0123456789abcdef";
	unsigned long long	reverse;

	if (base == 0)
		return (NULL);
	if ((ptr = exception(n)) != NULL)
		return (ptr);
	neg = n < 0 ? -1 : 0;
	reverse = (neg == -1 ? (unsigned long long)(n * -1)
			: (unsigned long long)n);
	j = lo_filler(reverse, 0, base, neg);
	if (!(ptr = lo_strnew((size_t)j)))
		return (NULL);
	j--;
	while (reverse >= 1)
	{
		ptr[j--] = converter[(reverse % (unsigned long long)base)];
		reverse /= (unsigned long long)base;
	}
	neg == -1 ? ptr[j] = '-' : neg;
	return (ptr);
}
