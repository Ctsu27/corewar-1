/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:48:15 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:25:34 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dasm.h"

int				check_magic_bits(t_env *e, int fd)
{
	int				ret;
	int				i;
	unsigned char	buf[4];

	if ((ret = read(fd, buf, 4)) == -1)
	{
		ke_putstr("error on read\n");
		close(fd);
		return (-1);
	}
	if (ret != 4)
	{
		ke_putstr("error on magic bits\n");
		return (-1);
	}
	i = -1;
	while (++i < 4)
	{
		if (buf[i] != ((e->header.magic >> ((4 - i - 1) * 8)) & 0xff))
		{
			ke_putstr("error on magic bits\n");
			return (-1);
		}
	}
	return (0);
}

int				take_name(t_env *e, int fd)
{
	int		ret;

	if ((ret = read(fd, e->header.prog_name, PROG_NAME_LENGTH)) == -1)
	{
		ke_putstr("error on read\n");
		close(fd);
		return (-1);
	}
	if (ret < PROG_NAME_LENGTH)
	{
		ke_putstr("error: prog_name too small\n");
		close(fd);
		return (-1);
	}
	return (0);
}

int				take_comment(t_env *e, int fd)
{
	int		ret;

	if ((ret = read(fd, e->header.comment, COMMENT_LENGTH)) == -1)
	{
		ke_putstr("error on read\n");
		close(fd);
		return (-1);
	}
	if (ret < COMMENT_LENGTH)
	{
		ke_putstr("error: comment too small\n");
		close(fd);
		return (-1);
	}
	return (0);
}

unsigned int	take_prog_size(int fd)
{
	int				ret;
	unsigned int	size;
	unsigned char	buf[4];

	if ((ret = read(fd, buf, 4)) == -1)
	{
		ke_putstr("error on read\n");
		close(fd);
		return (0);
	}
	if (ret < 4)
	{
		ke_putstr("error: prog_size too small\n");
		close(fd);
		return (0);
	}
	size = buf[3] | (buf[2] << 8) | (buf[1] << 16) | (buf[0] << 24);
	return (size);
}

int				dasm_check_file(t_env *e, int fd)
{
	if (check_magic_bits(e, fd) == -1)
		return (-1);
	if (take_name(e, fd) == -1)
		return (-1);
	if (dump_prog_size(fd, 1) == -1
			|| (e->header.prog_size = take_prog_size(fd)) == 0)
		return (-1);
	if (take_comment(e, fd) == -1)
		return (-1);
	if (dump_prog_size(fd, 0) == -1)
		return (-1);
	if (check_champion(e, fd) == -1)
		return (-1);
	return (0);
}
