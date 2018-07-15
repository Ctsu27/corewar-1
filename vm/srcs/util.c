/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:02:28 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/01 14:14:58 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int					ft_return_value(t_env *env, t_process *process, int i)
{
	int		value;

	if (process->args_type[i] == T_REG)
		value = process->reg_tab[process->args_value[i] - 1];
	else if (process->args_type[i] == T_IND)
		value = (int)ft_read_arena(env->arena, process->pc
				+ (unsigned int)process->args_value[i], REG_SIZE);
	else
		value = process->args_value[i];
	return (value);
}

unsigned int		ft_getbinary_numb(unsigned char *line,
					unsigned int index, unsigned int octet)
{
	unsigned int	number;
	unsigned int	i;

	i = 0;
	number = 0;
	while (i < octet)
		number = (number << 8) + line[index + i++];
	return (number);
}

int					cast_short(int value)
{
	short x;

	x = (short)value;
	value = (int)x;
	return (value);
}

int					check_last_process(t_env *env, t_process *process)
{
	t_list *curr;

	curr = env->progs;
	while (curr->next)
		curr = curr->next;
	if (((t_process*)curr->content) == process)
		return (1);
	return (0);
}

int					ope_size_type(int type_code, int opcode)
{
	if (type_code == REG_CODE)
		return (1);
	if (type_code == IND_CODE)
		return (2);
	return ((g_op_tab[opcode - 1].size_dir == true) ? 2 : 4);
}
