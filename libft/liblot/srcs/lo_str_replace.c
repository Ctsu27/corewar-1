/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:49:27 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:56 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_str_replace(char *str, char old, char mew)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = mew;
		++i;
	}
	return (str);
}
