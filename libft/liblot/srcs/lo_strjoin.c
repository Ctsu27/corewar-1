/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:46 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:59 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strjoin(char const *s1, char const *s2)
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
	return (ptr);
}
