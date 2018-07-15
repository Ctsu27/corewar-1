/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:23:27 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/29 12:37:53 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_lldi_op(t_process *process, t_env *env)
{
	unsigned int	value;
	int				*tab_value;

	scan_coding_param(process, env);
	if (!check_coding_param(process->args_type, process->opcode)
			|| !get_instruction_value(process, env))
	{
		move_process(process, env);
		return ;
	}
	tab_value = process->args_value;
	if (process->args_type[0] == T_IND)
		tab_value[0] = (int)ft_read_arena(env->arena, process->pc
				+ (unsigned int)tab_value[0], REG_SIZE);
	else if (process->args_type[0] == T_REG)
		tab_value[0] = process->reg_tab[tab_value[0] - 1];
	if (process->args_type[1] == T_REG)
		tab_value[1] = process->reg_tab[tab_value[1] - 1];
	value = process->pc + (unsigned int)(tab_value[0] + tab_value[1]);
	process->reg_tab[tab_value[2] - 1] = (int)ft_read_arena(env->arena,
			value, REG_SIZE);
	process->carry = (process->reg_tab[tab_value[2] - 1] == 0 ? 1 : 0);
	move_process(process, env);
}

void			ft_lld_op(t_process *process, t_env *env)
{
	int		value;

	scan_coding_param(process, env);
	if (!check_coding_param(process->args_type, process->opcode)
			|| !get_instruction_value(process, env))
	{
		move_process(process, env);
		return ;
	}
	value = process->args_value[0];
	if (process->args_type[0] == T_IND)
		value = (int)ft_read_arena(env->arena, process->pc
				+ (unsigned int)value, REG_SIZE);
	process->reg_tab[process->args_value[1] - 1] = value;
	if (value == 0)
		process->carry = 1;
	else
		process->carry = 0;
	move_process(process, env);
}
