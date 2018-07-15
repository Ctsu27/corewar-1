/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:58:06 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/23 15:58:39 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		dump_prog_size(int fd, char error)
{
	int				ret;
	unsigned char	buf[4];

	if ((ret = read(fd, buf, 4)) == -1)
	{
		ke_putstr("error on read\n");
		close(fd);
		return (-1);
	}
	if (ret < 4)
	{
		if (error == 1)
			ke_putstr("error: prog_size too small\n");
		else
			ke_putstr("error: dumps header\n");
		close(fd);
		return (-1);
	}
	return (0);
}
