/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:59:38 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/07 13:26:45 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_fd		*mng(t_fd **strct, char **line, int *bool, int *boolbis)
{
	int i;

	i = 0;
	while ((*strct)->tmp != NULL)
	{
		i = lo_strlen_to((*strct)->tmp, '\n');
		if (i == 0 && (*strct)->tmp[0] != '\n')
		{
			*line = lo_strdup_free((*strct)->tmp, line);
			lo_strdel(&(*strct)->tmp);
			*boolbis = 1;
		}
		else
		{
			*line = lo_strsub_free((*strct)->tmp, 0, (size_t)i, line);
			if ((i + 2) <= lo_strlen((*strct)->tmp))
				(*strct)->tmp = lo_strdup_free((*strct)->tmp + i
						+ 1, &((*strct)->tmp));
			else
				lo_strdel(&((*strct)->tmp));
			*bool = 1;
		}
		return (*strct);
	}
	return (*strct);
}

static t_list	*list_check(int fd, t_list *lst,
		t_list **lst_tmp, t_filler **ltl)
{
	(*ltl)->bool = 0;
	(*ltl)->boolbis = 0;
	(*ltl)->lll = 0;
	if (!lst)
	{
		lst = lo_lst_new(sizeof(t_fd));
		((t_fd*)(lst->content))->fd = fd;
	}
	*lst_tmp = lst;
	while (lst->next != NULL && fd != ((t_fd*)(lst->content))->fd)
		lst = lst->next;
	if (lst->next == NULL && fd != ((t_fd*)(lst->content))->fd)
	{
		lo_lst_add_end(&lst, lo_lst_new(sizeof(t_fd)));
		lst = lst->next;
	}
	((t_fd*)(lst->content))->fd = fd;
	return (lst);
}

static int		job(char *buf, t_list *lst, int *bool, char **line)
{
	int		i;
	char	*omg;

	i = lo_strlen_to(buf, '\n');
	(i == 0 && buf[0] != '\n') ? *line = lo_strjoin_free(*line, buf, line) : 0;
	(i == 0 && buf[0] != '\n') ? *bool = 1 : 0;
	if (i != 0 || buf[0] == '\n')
	{
		if ((*line)[0] == '\0')
			*line = lo_strsub_free(buf, 0, (size_t)i, line);
		else
		{
			omg = lo_strsub(buf, 0, (size_t)i);
			*line = lo_strjoin_free(*line, omg, line);
			lo_strdel(&omg);
		}
		if ((i + 2) <= lo_strlen(buf))
			((t_fd*)(lst->content))->tmp = lo_strdup_free(buf + i + 1,
				&(((t_fd*)(lst->content))->tmp));
		else
			lo_strdel(&(((t_fd*)(lst->content))->tmp));
		return (1);
	}
	return (0);
}

static int		lo_filler(t_list **lst, t_list **lst_tmp,
		t_filler **ltl, char **line)
{
	int unused;

	(*ltl)->ret = (int)read(((t_fd*)((*lst)->content))->fd,
			(*ltl)->buf, BUFF_SIZE);
	if ((*ltl)->ret == -1 || !((*ltl)->ret))
	{
		(*ltl)->boolbis == 1 ? (*ltl)->bool = 1 : (*ltl)->bool;
		unused = ((*ltl)->ret == -1 ? -1 : (*ltl)->bool);
		lo_strdel(&((*ltl)->buf));
		free(*ltl);
		return (unused);
	}
	(*ltl)->buf[(*ltl)->ret] = '\0';
	(*ltl)->ret ? (*ltl)->bool = 0 : 0;
	if (job((*ltl)->buf, *lst, &((*ltl)->bool), line))
	{
		*lst = *lst_tmp;
		lo_strdel(&((*ltl)->buf));
		free(*ltl);
		return (1);
	}
	return (-42);
}

int				lo_get_next_line(int fd, char **line)
{
	t_filler		*ltl;
	t_list			*lst_tmp;
	static t_list	*lst;

	if (fd < 0 || !line || !(ltl = lo_memalloc(sizeof(t_filler)))
			|| !(*line = lo_strnew(BUFF_SIZE))
			|| !(ltl->buf = lo_strnew(BUFF_SIZE)))
		return (-1);
	lst = list_check(fd, lst, &lst_tmp, &ltl);
	while (1)
	{
		if (((t_fd*)(lst->content))->tmp)
		{
			mng((t_fd**)&(lst->content), line, &(ltl->bool), &(ltl->boolbis));
			if (ltl->bool == 1)
			{
				lst = lst_tmp;
				lo_strdel(&(ltl->buf));
				free(ltl);
				return (1);
			}
		}
		if ((fd = lo_filler(&lst, &lst_tmp, &ltl, line)) != -42)
			return (fd);
	}
}
