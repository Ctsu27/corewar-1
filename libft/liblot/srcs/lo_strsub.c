/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:14:25 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:03 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strsub(char const *s, unsigned int start, size_t len)
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
	return (ptr);
}
