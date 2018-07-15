/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:17:21 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/23 16:30:46 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				lo_is_integer(char *str)
{
	int i;

	if (lo_is_number(str) == 0)
		return (0);
	i = lo_strlen(str);
	str[0] == '-' ? --i : 0;
	if (i > 10)
		return (0);
	if (i < 10)
		return (1);
	i = 0;
	(str[0] == '-') ? ++i : 0;
	return ((i == 0) ? lo_strcmp(&str[i], "2147483647") <= 0
			: lo_strcmp(&str[i], "2147483648") <= 0);
}
