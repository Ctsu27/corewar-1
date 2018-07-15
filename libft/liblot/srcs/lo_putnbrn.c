/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:46:51 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:53 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_putnbrn(int n)
{
	if (n == -2147483648)
	{
		n = 147483648;
		lo_putchar('-');
		lo_putchar('2');
	}
	else if (n < 0)
	{
		lo_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		lo_putnbr(n / 10);
		lo_putnbr(n % 10);
	}
	else
	{
		lo_putchar((char)n + '0');
	}
	lo_putchar('\n');
}
