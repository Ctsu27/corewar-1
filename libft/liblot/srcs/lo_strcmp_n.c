/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strcmp_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:58:53 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:57 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		lo_strcmp_n(const char *s1, const char *s2, int size)
{
	while (*s1 && *s2 && --size)
	{
		if ((*s1 - *s2) != 0)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
