/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:55:02 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/01 17:28:52 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		indirect_size(t_process *process, int jump_value, t_env *env)
{
	jump_value = cast_short(jump_value);
	if (env->arena[process->pc] != 13 && env->arena[process->pc] != 14
			&& env->arena[process->pc] != 15)
		jump_value = jump_value + (1 - 1);
	return (jump_value);
}

void			set_size(t_process *process)
{
	unsigned int i;

	i = 0;
	while (i < g_op_tab[process->opcode - 1].n_arg)
	{
		process->args_type[i] == T_REG ?
			process->args_size[i] = 1 : 0;
		if (process->args_type[i] == T_DIR)
		{
			if (g_op_tab[process->opcode - 1].size_dir == 0)
				process->args_size[i] = DIR_SIZE;
			else
				process->args_size[i] = IND_SIZE;
		}
		process->args_type[i] == T_IND ?
			process->args_size[i] = IND_SIZE : 0;
		++i;
	}
}

static int		fill_value(unsigned int space, unsigned int i,
				t_process *process, t_env *env)
{
	if (process->args_type[i] == 0)
		return (0);
	else if (process->args_type[i] == T_REG)
	{
		if ((process->args_value[i] = (int)ft_read_arena(env->arena,
				process->pc + space, 1)) > REG_NUMBER
				|| (process->args_value[i] = (int)ft_read_arena(env->arena,
						process->pc + space, 1)) == 0)
			return (0);
	}
	else if (process->args_type[i] == T_DIR)
	{
		if (g_op_tab[process->opcode - 1].size_dir == 1)
			process->args_value[i] = indirect_size(process,
			(int)ft_read_arena(env->arena, process->pc + space, IND_SIZE), env);
		else
			process->args_value[i] = (int)ft_read_arena(env->arena,
			process->pc + space, (unsigned int)process->args_size[i]);
	}
	else if (process->args_type[i] == T_IND)
		process->args_value[i] = indirect_size(process,
		(int)ft_read_arena(env->arena, process->pc + space, IND_SIZE), env);
	return (1);
}

int				get_instruction_value(t_process *process, t_env *env)
{
	unsigned int	i;
	unsigned int	space;
	int				isok;

	i = 0;
	isok = 1;
	space = 1 + (g_op_tab[process->opcode - 1].isopc * env->nbr_args);
	set_size(process);
	while (i < g_op_tab[process->opcode - 1].n_arg)
	{
		if (fill_value(space, i, process, env) == 0)
			isok = 0;
		space += (unsigned int)process->args_size[i];
		++i;
	}
	return (isok);
}
