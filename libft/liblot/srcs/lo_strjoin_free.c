/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:37:43 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:59 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strjoin_free(char *s1, char *s2, char **out)
{
	int		i;
	char	*ptr;

	if (!(s1) || !(s2))
		return (NULL);
	i = lo_strlen(s1) + lo_strlen(s2);
	if (!(ptr = lo_strnew((size_t)i)))
		return (NULL);
	if (!(ptr = lo_strcpy(ptr, s1)))
		return (NULL);
	if (!(ptr = lo_strcat(ptr, s2)))
		return (NULL);
	if (*out)
		lo_strdel(out);
	return (ptr);
}
