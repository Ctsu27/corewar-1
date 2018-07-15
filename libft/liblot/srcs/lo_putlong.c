/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:56:25 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:52 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_putlong(long long int n)
{
	unsigned long long nbr;

	nbr = 0;
	if (n == LONG_MIN)
	{
		lo_putstr("-9223372036854775808");
		return ;
	}
	else if (n < 0)
	{
		lo_putchar('-');
		nbr = (unsigned long long)(n * -1);
	}
	else
		nbr = (unsigned long long)n;
	if (nbr > 9)
	{
		lo_putlong(nbr / 10);
		lo_putlong(nbr % 10);
	}
	else
		lo_putchar((char)nbr + '0');
}
