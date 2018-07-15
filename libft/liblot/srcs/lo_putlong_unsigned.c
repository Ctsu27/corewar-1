/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_putlong_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:56:04 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:52 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_putlong_unsigned(unsigned long long n)
{
	if (n > 9)
	{
		lo_putlong_unsigned(n / 10);
		lo_putlong_unsigned(n % 10);
	}
	else
		lo_putchar((char)n + '0');
}
