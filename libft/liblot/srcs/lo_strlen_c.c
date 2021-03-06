/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strlen_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:15:29 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:00 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			lo_strlen_c(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			--i;
		++i;
		str++;
	}
	return (i);
}
