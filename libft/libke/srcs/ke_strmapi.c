/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:35:26 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:35:27 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ke_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ke_strlen(s);
	i = 0;
	dest = NULL;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
