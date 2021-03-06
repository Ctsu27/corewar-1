/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:57:23 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:12:04 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_swap(int *a, int *b)
{
	int c;

	if (!a || !b)
		return ;
	c = *a;
	*a = *b;
	*b = c;
}
