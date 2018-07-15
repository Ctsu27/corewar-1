/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:33:44 by kehuang           #+#    #+#             */
/*   Updated: 2018/02/08 15:33:46 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ke_rec_putnbr_fd(unsigned int nb, int fd)
{
	if (nb / 10 != 0)
		ke_rec_putnbr_fd(nb / 10, fd);
	ke_putchar_fd(nb % 10 + '0', fd);
}

void		ke_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ke_putchar_fd('-', fd);
		ke_rec_putnbr_fd(-n, fd);
	}
	else
		ke_rec_putnbr_fd(n, fd);
}
