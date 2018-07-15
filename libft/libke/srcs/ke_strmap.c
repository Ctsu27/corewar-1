/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:35:21 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:35:23 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ke_lenstr(char const *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char		*ke_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ke_lenstr(s);
	i = 0;
	dest = NULL;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
