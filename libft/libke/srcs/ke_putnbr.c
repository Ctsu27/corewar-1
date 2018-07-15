/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:33:40 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:33:41 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ke_rec_putnbr(unsigned int nb)
{
	if (nb / 10 != 0)
		ke_rec_putnbr(nb / 10);
	ke_putchar(nb % 10 + '0');
}

void		ke_putnbr(int n)
{
	if (n < 0)
	{
		ke_putchar('-');
		ke_rec_putnbr(-n);
	}
	else
		ke_rec_putnbr(n);
}
