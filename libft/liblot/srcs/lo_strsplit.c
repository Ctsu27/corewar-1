/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:03:00 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:03 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			**lo_tab(char **tab, char const *s, int k, int c)
{
	int i;
	int start;

	i = 0;
	while (s[i])
	{
		s[i] == c ? i++ : i;
		if (s[i] != c && s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[k] = lo_strsub(s, (unsigned int)start, (size_t)(i - start));
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char				**lo_strsplit(char const *s, char c)
{
	char	**tab;

	if (!(s))
		return (0);
	if (!(tab = (char**)lo_memalloc(sizeof(char*)
					* (unsigned long)(lo_word_nbr(s, c) + 1))))
		return (0);
	tab = lo_tab(tab, s, 0, c);
	return (tab);
}
