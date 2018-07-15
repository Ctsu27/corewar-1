/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ke_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:57:37 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/05 21:45:13 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ke_get_next_line.h"

static char	*ke_take_rest(char *t)
{
	char	*tmp;

	tmp = t;
	if ((t = ke_strsub(ke_strchr(t, '\n'), 1,
					ke_strlen(ke_strchr(t, '\n')) - 1)) == NULL)
	{
		ke_strdel(&tmp);
		return (NULL);
	}
	ke_strdel(&tmp);
	return (t);
}

static char	*ke_dup_zero(char *t)
{
	char	*tmp;

	tmp = t;
	if ((t = ke_strnew(0)) == NULL)
	{
		ke_strdel(&tmp);
		return (NULL);
	}
	ke_strdel(&tmp);
	return (t);
}

static int	ke_get_string(char **line, char *buf, const int fd, char **stock)
{
	if (ke_strchr(stock[fd], '\n'))
	{
		if ((*line = ke_strsub(stock[fd], 0, ke_strlen(stock[fd])
						- ke_strlen(ke_strchr(stock[fd], '\n')))) == NULL)
			return (-1);
		if ((stock[fd] = ke_take_rest(stock[fd])) == NULL)
		{
			ke_strdel(line);
			return (-1);
		}
		return (1);
	}
	if (stock[fd][0] != '\0')
	{
		if ((*line = ke_strjoin(stock[fd], buf)) == NULL)
			return (-1);
		if ((stock[fd] = ke_dup_zero(stock[fd])) == NULL)
		{
			ke_strdel(line);
			return (-1);
		}
		return (1);
	}
	return (0);
}

static int	take_line(char **line, char *buf, const int fd, char **stock)
{
	int		ret;
	int		rf;

	while ((rf = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		buf[rf] = '\0';
		if ((stock[fd] = ke_strjoin_free(stock[fd], buf)) == NULL)
			return (-1);
		if (!(ke_strchr(buf, '\n')))
			break ;
	}
	if ((ret = ke_get_string(line, buf, fd, stock)) == -1)
		return (-1);
	if (ret == 1)
		return (1);
	ke_strdel(&stock[fd]);
	return (0);
}

int			ke_get_next_line(const int fd, char **line, char **noleaks)
{
	char		buf[GNL_BUFF_SIZE + 1];
	char		tmp[1];
	static char	*stock[GNL_OPEN_MAX];
	int			ret_val;

	if (fd < 0 || fd > GNL_OPEN_MAX || line == NULL || read(fd, tmp, 0) == -1)
		return (-1);
	if (!stock[fd])
		if ((stock[fd] = ke_strnew(0)) == NULL)
			return (-1);
	ret_val = take_line(line, buf, fd, stock);
	*noleaks = stock[fd];
	return (ret_val);
}
