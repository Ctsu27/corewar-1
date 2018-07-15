/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:25:39 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/22 17:25:46 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ke_putunbr_fd(unsigned int nb, int fd)
{
	if (nb / 10 != 0)
		ke_putunbr_fd(nb / 10, fd);
	ke_putchar_fd((char)(nb % 10 + '0'), fd);
}
