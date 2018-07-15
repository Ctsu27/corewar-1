/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:19:14 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:09:37 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static void	init_lst_on_null_case(t_lst *lst)
{
	if (lst != NULL)
	{
		lst->data.octpc = -1;
		lst->data.opcode = -1;
		lst->data.param = NULL;
		lst->data.type = NULL;
		lst->data.is_label = NULL;
		lst->data.head_label = NULL;
		lst->data.param_label[0] = NULL;
		lst->data.param_label[1] = NULL;
		lst->data.param_label[2] = NULL;
		lst->data.param_label[3] = 0;
		lst->data.y = 0;
	}
}

t_lst		*init_lst(t_data *data)
{
	t_lst	*lst;
	int		i;

	if ((lst = (t_lst *)malloc(sizeof(*lst))) == NULL)
		return (NULL);
	i = -1;
	if (data != NULL)
	{
		lst->data = *data;
		while (++i < 4)
			lst->data.param_label[i] = data->param_label[i];
		lst->data.y = data->y;
	}
	else
		init_lst_on_null_case(lst);
	lst->next = NULL;
	return (lst);
}

void		cat_lst(t_env *e, t_data *data)
{
	t_lst	*i;

	i = e->head;
	while (i->next != NULL)
		i = i->next;
	if ((i->next = init_lst(data)) == NULL)
		ft_exit_msg(e, "Error on memory allocation\n");
}

void		free_lst(t_lst *head)
{
	t_lst	*ptr;
	t_lst	*i;
	int		j;

	i = head;
	while (i != NULL)
	{
		j = -1;
		ptr = i;
		i = i->next;
		if (ptr->data.param != NULL)
			free(ptr->data.param);
		if (ptr->data.type != NULL)
			free(ptr->data.type);
		if (ptr->data.is_label != NULL)
			free(ptr->data.is_label);
		if (ptr->data.head_label != NULL)
			free_lst_lbl(ptr->data.head_label);
		while (++j < 4)
			if (ptr->data.param_label[j] != NULL)
				free(ptr->data.param_label[j]);
		if (ptr != NULL)
			free(ptr);
	}
}

void		print_lst_fd(t_lst *head, int fd)
{
	t_lst			*ptr;
	unsigned int	val;
	int				len;
	int				i;

	ptr = head;
	while ((ptr = ptr->next) != NULL)
	{
		ke_putuchar_fd((unsigned char)(ptr->data.opcode + 1), fd);
		if (g_op_tab[ptr->data.opcode].isopc)
			ke_putuchar_fd((unsigned char)ptr->data.octpc, fd);
		i = -1;
		while (++i < g_op_tab[ptr->data.opcode].n_arg)
		{
			len = ope_size_type(ptr->data.type[i], ptr->data.opcode);
			val = (len != 1) ? (unsigned int)(0xff << (8 * (len - 1)))
				: (unsigned int)0xff;
			while (val > 0)
			{
				ke_putuchar_fd(((unsigned char)((ptr->data.param[i] & val)
							>> (unsigned char)(8 * (ft_octlen(val) - 1)))), fd);
				val = val >> 8;
			}
		}
	}
}
