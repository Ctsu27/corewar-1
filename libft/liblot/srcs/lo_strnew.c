/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:57:45 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:02 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*lo_strnew(size_t size)
{
	char *ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	lo_bzero(ptr, size + 1);
	return (ptr);
}
