/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:29:25 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:48 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*lo_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = (void*)malloc(size)))
		return (0);
	lo_bzero(ptr, size);
	return (ptr);
}
