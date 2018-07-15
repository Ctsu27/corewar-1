/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:55:58 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:24:21 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dasm.h"

t_lst		*init_lst(t_data *data)
{
	t_lst	*lst;

	if ((lst = (t_lst *)malloc(sizeof(*lst))) == NULL)
		return (NULL);
	if (data != NULL)
	{
		lst->data.opcode = data->opcode;
		lst->data.octpc = data->octpc;
		lst->data.param = data->param;
		lst->data.type = data->type;
	}
	else
	{
		lst->data.opcode = -1;
		lst->data.octpc = -1;
		lst->data.param = NULL;
		lst->data.type = NULL;
	}
	lst->next = NULL;
	return (lst);
}

void		free_lst(t_lst *head)
{
	t_lst	*ptr;
	t_lst	*i;

	i = head;
	while (i != NULL)
	{
		ptr = i;
		i = i->next;
		if (ptr->data.param != NULL)
			free(ptr->data.param);
		if (ptr->data.type != NULL)
			free(ptr->data.type);
		if (ptr != NULL)
			free(ptr);
	}
}

void		cat_lst(t_env *e, t_data *data)
{
	t_lst	*i;

	i = e->head;
	while (i->next != NULL)
		i = i->next;
	if ((i->next = init_lst(data)) == NULL)
	{
		free_lst(e->head);
		exit(-1);
	}
}

static void	print_header(t_env *e, int fd)
{
	ke_putstr_fd(NAME_CMD_STRING, fd);
	ke_putchar_fd(' ', fd);
	ke_putchar_fd('\"', fd);
	ke_putstr_fd(e->header.prog_name, fd);
	ke_putchar_fd('\"', fd);
	ke_putchar_fd('\n', fd);
	ke_putstr_fd(COMMENT_CMD_STRING, fd);
	ke_putchar_fd(' ', fd);
	ke_putchar_fd('\"', fd);
	ke_putstr_fd(e->header.comment, fd);
	ke_putchar_fd('\"', fd);
	ke_putstr_fd("\n\n", fd);
}

void		lst_print(t_env *e, int fd)
{
	t_lst			*ptr;
	int				i;

	ptr = e->head;
	print_header(e, fd);
	while ((ptr = ptr->next) != NULL)
	{
		ke_putstr_fd(g_op_tab[ptr->data.opcode - 1].ope, fd);
		ke_putchar_fd(' ', fd);
		i = -1;
		while (++i < g_op_tab[ptr->data.opcode - 1].n_arg)
		{
			if (ptr->data.type[i] == reg)
				ke_putchar_fd('r', fd);
			else if (ptr->data.type[i] == dir)
				ke_putchar_fd(DIRECT_CHAR, fd);
			ke_putunbr_fd(ptr->data.param[i], fd);
			if (i < g_op_tab[ptr->data.opcode - 1].n_arg - 1)
			{
				ke_putchar_fd(SEPARATOR_CHAR, fd);
				ke_putchar_fd(' ', fd);
			}
		}
		ke_putchar_fd('\n', fd);
	}
}
