/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:30:25 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:30:30 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ke_nbrlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ke_neg_itoa(char *dest, int index, unsigned int n)
{
	n = -n;
	while (index > 0)
	{
		dest[index - 1] = n % 10 + '0';
		n = n / 10;
		index--;
	}
	dest[0] = '-';
}

char		*ke_itoa(int n)
{
	char	*dest;
	int		index;

	index = ke_nbrlen(n);
	dest = NULL;
	dest = (char *)malloc(sizeof(*dest) * (index + 1));
	if (dest == NULL)
		return (NULL);
	dest[index] = '\0';
	if (n < 0)
		ke_neg_itoa(dest, index, n);
	else
	{
		while (index > 0)
		{
			dest[index - 1] = n % 10 + '0';
			n = n / 10;
			index--;
		}
	}
	return (dest);
}
