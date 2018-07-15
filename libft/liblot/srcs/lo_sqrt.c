/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:55:02 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:56 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		lo_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	while ((i * i) < nb)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}