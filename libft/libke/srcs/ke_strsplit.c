/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:36:17 by kehuang           #+#    #+#             */
/*   Updated: 2018/04/18 17:05:43 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ke_count_word(char const *s, char c)
{
	int		nb_word;
	int		i;

	nb_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nb_word++;
			while (s[i] != c && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (nb_word);
}

static int	ke_word_len(char const *s, int i, char c)
{
	int		len;

	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	*ke_copy_word(const char *s, int *i, char c)
{
	char	*dest;
	int		len_word;
	int		j;

	len_word = ke_word_len(s, *i, c);
	if ((dest = (char *)malloc(sizeof(*dest) * (len_word + 1))) == NULL)
		return (NULL);
	dest[len_word] = '\0';
	j = 0;
	while (j < len_word)
	{
		dest[j] = s[*i];
		*i = *i + 1;
		j++;
	}
	return (dest);
}

char		**ke_strsplit(char const *s, char c)
{
	char	**dest;
	int		nb_word;
	int		i_word;
	int		i;

	if (!s)
		return (NULL);
	nb_word = ke_count_word(s, c);
	if ((dest = (char **)malloc(sizeof(*dest) * (nb_word + 1))) == NULL)
		return (NULL);
	i_word = 0;
	i = 0;
	while (i_word < nb_word)
	{
		while (s[i] == c)
			i++;
		if ((dest[i_word] = ke_copy_word(s, &i, c)) == NULL)
			return (NULL);
		i_word++;
	}
	dest[i_word] = 0;
	return (dest);
}
