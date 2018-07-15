/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strnew_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:14:59 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:02 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strnew_free(size_t size, char **str)
{
	char *ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	lo_bzero(ptr, size + 1);
	if (*str)
		lo_strdel(str);
	return (ptr);
}
