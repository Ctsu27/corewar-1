/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:30:33 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:30:37 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ke_nb_len(int n, int base)
{
	int		len;

	len = 0;
	if (n < 0 && base == 10)
		len = 1;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static char	*ke_convert(char *str, unsigned int n, int base, int index)
{
	static char	strbase[17] = "0123456789abcdef";

	while (index > 0)
	{
		str[index - 1] = strbase[n % base];
		n = n / base;
		index--;
	}
	return (str);
}

char		*ke_itoa_base(int n, int base)
{
	char	*dest;
	int		index;

	if (base < 2 || base > 16)
		return (NULL);
	index = ke_nb_len(n, base);
	if ((dest = (char *)malloc(sizeof(*dest) * (index + 1))) == NULL)
		return (NULL);
	dest[index] = '\0';
	dest = (n < 0) ? ke_convert(dest, -n, base, index)
		: ke_convert(dest, n, base, index);
	if (n < 0 && base == 10)
		dest[0] = '-';
	return (dest);
}
