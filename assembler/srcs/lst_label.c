/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:43:17 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/22 16:27:02 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

t_lst_lbl	*init_lst_lbl(char *label_name)
{
	t_lst_lbl	*lst;

	if ((lst = (t_lst_lbl *)malloc(sizeof(*lst))) == NULL)
		return (NULL);
	lst->label_name = label_name;
	lst->next = NULL;
	return (lst);
}

void		cat_lst_lbl(t_env *e, char *label_name)
{
	t_lst_lbl	*ptr;

	if (e->tmp == NULL)
		return ;
	ptr = e->tmp;
	while (ptr->next != NULL)
		ptr = ptr->next;
	if ((ptr->next = init_lst_lbl(label_name)) == NULL)
		ft_exit_msg(e, "Error on memory allocation\n");
}

void		free_lst_lbl(t_lst_lbl *head)
{
	t_lst_lbl	*ptr;
	t_lst_lbl	*i;

	i = head;
	while (i != NULL)
	{
		ptr = i;
		i = i->next;
		if (ptr->label_name != NULL)
			free(ptr->label_name);
		if (ptr != NULL)
			free(ptr);
	}
}

void		print_lst_lbl(t_lst_lbl *head)
{
	t_lst_lbl	*i;

	i = head;
	while (i != NULL)
	{
		if (i->label_name != NULL)
			ke_putendl(i->label_name);
		i = i->next;
	}
}
