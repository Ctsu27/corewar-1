/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:08:29 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/24 13:46:24 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

t_bool			last_label_finded(t_env *e, char *root_label)
{
	t_lst_lbl	*i;

	i = e->tmp;
	if (i != NULL && i->next != NULL)
	{
		while ((i = i->next) != NULL)
			if (ke_strcmp(i->label_name, root_label) == 0)
				return (true);
	}
	return (false);
}

unsigned int	take_lbl_address_value(t_lst *root, int addr,
		int lab_addr, int i)
{
	unsigned int	val;

	if (root->data.type[i] == indir)
		val = (unsigned int)0xffff;
	else if ((root->data.opcode >= 8 && root->data.opcode <= 11)
			|| root->data.opcode == 13 || root->data.opcode == 14)
		val = (unsigned int)0xffff;
	else if (root->data.opcode == 0 || root->data.opcode == 1
			|| root->data.opcode == 5 || root->data.opcode == 6
			|| root->data.opcode == 7 || root->data.opcode == 12)
		val = (unsigned int)0xffffffff;
	else
		val = (unsigned int)0xffff;
	return ((lab_addr <= addr) ? (val - (unsigned int)(addr - lab_addr - 2))
			: (unsigned int)(lab_addr - addr + 1));
}

int				jump_addr(t_lst *i)
{
	int		loop;
	int		size;

	size = 0;
	if (i->data.param != NULL)
	{
		loop = 0;
		size = 1;
		while (loop < g_op_tab[i->data.opcode].n_arg)
		{
			size = size + ope_size_type(i->data.type[loop], i->data.opcode);
			loop++;
		}
		if (g_op_tab[i->data.opcode].isopc)
			size = size + 1;
	}
	return (size);
}

int				check_label_dump(t_env *e, t_lst *root, int addr, int index)
{
	t_lst			*i;
	int				loop;
	int				size;
	int				lab_addr;

	if (e->tmp == NULL && e->tmp->next == NULL)
	{
		ke_putstr("error on check dump\n");
		return (-1);
	}
	i = e->head;
	lab_addr = 0;
	while ((i = i->next) != NULL)
	{
		loop = 0;
		size = 1;
		lab_addr = lab_addr + jump_addr(i);
	}
	if (last_label_finded(e, root->data.param_label[index]) == true)
		root->data.param[index] = take_lbl_address_value(root, addr,
				lab_addr, index);
	return (0);
}
