/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:50:00 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/05 21:20:47 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static t_bool	label_finded(t_lst *i, char *root_label)
{
	t_lst_lbl	*l;

	l = NULL;
	l = i->data.head_label;
	if (l != NULL)
		while ((l = l->next) != NULL)
			if (ke_strcmp(l->label_name, root_label) == 0)
				return (true);
	return (false);
}

static int		check(t_env *e, t_lst *root, int addr, int index)
{
	t_lst			*i;
	int				loop;
	int				size;
	int				lab_addr;

	i = e->head;
	lab_addr = 0;
	while ((i = i->next) != NULL)
	{
		if (label_finded(i, root->data.param_label[index]) == true)
			break ;
		loop = 0;
		size = 1;
		lab_addr = lab_addr + jump_addr(i);
	}
	if (i == NULL
			&& last_label_finded(e, root->data.param_label[index]) == true)
		return (0);
	else if (i == NULL)
		return (-1);
	root->data.param[index] = take_lbl_address_value(root, addr, lab_addr,
			index);
	return (0);
}

int				label_check(t_env *e)
{
	t_lst	*i;
	int		j;
	int		actual_addr;

	i = e->head;
	if (i == NULL)
		return (-1);
	actual_addr = 1;
	while ((i = i->next) != NULL)
	{
		j = -1;
		while (++j < 3)
			if (i->data.param_label[j] != NULL)
				if (check(e, i, actual_addr, j) == -1 || (e->tmp != NULL
							&& check_label_dump(e, i, actual_addr, j) == -1))
				{
					ke_putstr("error label\nline : ");
					ke_putnbr(i->data.y);
					ke_putstr("\n");
					return (-1);
				}
		actual_addr = actual_addr + jump_addr(i);
	}
	return (0);
}
