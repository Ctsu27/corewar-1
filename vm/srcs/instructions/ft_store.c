/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:31:23 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/29 12:39:15 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_st(t_process *process, t_env *env)
{
	int	value;
	int	*tab_value;

	scan_coding_param(process, env);
	if (!check_coding_param(process->args_type, process->opcode)
			|| !get_instruction_value(process, env))
	{
		move_process(process, env);
		return ;
	}
	value = process->reg_tab[process->args_value[0] - 1];
	tab_value = process->args_value;
	if (process->args_type[1] == T_REG)
		process->reg_tab[process->args_value[1] - 1] = value;
	else if (process->args_type[1] == T_IND)
	{
		tab_value[1] %= IDX_MOD;
		ft_write_arena(env->arena, process->pc
				+ (unsigned int)tab_value[1], REG_SIZE, (unsigned int)value);
		if (env->visu.active)
			v_store(process->pc + (unsigned int)tab_value[1], env, \
					process->player, REG_SIZE);
	}
	move_process(process, env);
}

void			ft_sti_op(t_process *process, t_env *env)
{
	int				value;
	unsigned int	index;
	int				*tab_value;

	scan_coding_param(process, env);
	if (!check_coding_param(process->args_type, process->opcode)
			|| !get_instruction_value(process, env))
	{
		move_process(process, env);
		return ;
	}
	tab_value = process->args_value;
	if (process->args_type[1] == T_REG)
		tab_value[1] = process->reg_tab[tab_value[1] - 1];
	else if (process->args_type[1] == T_IND)
		tab_value[1] = (int)ft_read_arena(env->arena, process->pc
				+ (unsigned int)(tab_value[1] + IDX_MOD), DIR_SIZE);
	if (process->args_type[2] == T_REG)
		tab_value[2] = process->reg_tab[tab_value[2] - 1];
	index = process->pc + ((tab_value[1] + tab_value[2]) % IDX_MOD);
	value = process->reg_tab[tab_value[0] - 1];
	ft_write_arena(env->arena, index, REG_SIZE, (unsigned int)value);
	if (env->visu.active)
		v_store(index, env, process->player, REG_SIZE);
	move_process(process, env);
}
