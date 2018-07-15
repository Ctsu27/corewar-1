/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 05:21:10 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:53 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		n = 147483648;
		lo_putchar_fd('-', fd);
		lo_putchar_fd('2', fd);
	}
	else if (n < 0)
	{
		lo_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
	{
		lo_putnbr_fd(n / 10, fd);
		lo_putnbr_fd(n % 10, fd);
	}
	else
	{
		lo_putchar_fd((char)n + '0', fd);
	}
}
