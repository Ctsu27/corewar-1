/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_putnbr_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:57:02 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:53 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_putnbr_abs(long long int n)
{
	if (n == LONG_MIN)
	{
		lo_putstr("9223372036854775808");
		return ;
	}
	else if (n < 0)
		n = n * -1;
	if (n > 9)
	{
		lo_putnbr_abs(n / 10);
		lo_putnbr_abs(n % 10);
	}
	else
		lo_putchar((char)n + '0');
}
