/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:36:33 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/06 14:29:51 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ke_is_whitespaces(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	ke_len(const char *str)
{
	int		i;
	int		j;

	i = 0;
	while (ke_is_whitespaces(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	j = i;
	while (str[j] != '\0')
		j++;
	j--;
	while (ke_is_whitespaces(str[j]))
		j--;
	return ((i <= j) ? j + 1 - i : 0);
}

char		*ke_strtrim(char const *s)
{
	char	*dest;
	int		len;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	len = ke_len(s);
	i = 0;
	j = 0;
	if ((dest = (char *)malloc(sizeof(*dest) * (len + 1))) == NULL)
		return (NULL);
	while (ke_is_whitespaces(s[i]))
		i++;
	while (j < len)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
