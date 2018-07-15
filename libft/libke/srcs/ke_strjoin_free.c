/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 10:47:53 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/07 10:47:56 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ke_strjoin_free(char *s1, char *s2)
{
	char		*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = s1;
	if ((s1 = ke_strjoin(s1, s2)) == NULL)
	{
		ke_strdel(&tmp);
		return (NULL);
	}
	ke_strdel(&tmp);
	return (s1);
}
