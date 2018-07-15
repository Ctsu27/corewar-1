/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:47:33 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:04 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strsub_free(char const *s,
		unsigned int start, size_t len, char **out)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	if (!(s))
		return (ptr);
	i = 0;
	if (!(ptr = lo_strnew(len)))
		return (NULL);
	while (len > 0)
	{
		ptr[i] = s[start];
		i++;
		len--;
		start++;
	}
	if (*out)
		lo_strdel(out);
	return (ptr);
}
