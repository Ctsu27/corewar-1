/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:23:26 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:43 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*exception(int n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		if (!(ptr = lo_strnew(11)))
			return (NULL);
		ptr = lo_strcpy(ptr, "-2147483648");
		return (ptr);
	}
	else if (n == 0)
	{
		if (!(ptr = lo_strnew(1)))
			return (NULL);
		ptr = lo_strcpy(ptr, "0");
		return (ptr);
	}
	return (NULL);
}

static int		lo_filler(int i)
{
	int j;

	j = 0;
	while (i >= 1)
	{
		i /= 10;
		j++;
	}
	return (j);
}

char			*lo_itoa(int n)
{
	int		i;
	int		j;
	char	*ptr;
	int		neg;

	if ((ptr = exception(n)) != NULL)
		return (ptr);
	neg = n < 0 ? -1 : 0;
	neg == -1 ? n = n * -1 : n;
	i = n;
	j = 0;
	j = lo_filler(i);
	neg == -1 ? j++ : j;
	if (!(ptr = lo_strnew((size_t)j)))
		return (NULL);
	i = 0;
	j--;
	while (n >= 1)
	{
		ptr[j--] = (n % 10) + '0';
		n /= 10;
	}
	neg == -1 ? ptr[j] = '-' : neg;
	return (ptr);
}
