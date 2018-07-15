/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_int_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:35:34 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:41 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	lo_int_length(long long int i)
{
	int j;

	j = 0;
	if (i == 0)
		return (1);
	while (i >= 1 || i <= -1)
	{
		i /= 10;
		j++;
	}
	return (j);
}
