/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:17:09 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/06 10:15:27 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

void			jump_whitespace(char **str)
{
	while (**str == ' ' || **str == '\t')
		*str = *str + 1;
}

unsigned int	take_octpc(t_type *type, char n_arg)
{
	unsigned int	encoding;
	int				i;

	if (type == NULL || n_arg < 1 || n_arg > 3)
		return (0);
	encoding = 0;
	i = 0;
	while (i < n_arg)
	{
		encoding = (encoding << 2) | type[i];
		i++;
	}
	while (i < 4)
	{
		encoding = (encoding << 2);
		i++;
	}
	return (encoding);
}
