/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:46:52 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/01 14:16:24 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			scan_opcode(t_process *process, t_env *env)
{
	unsigned char	j;

	j = env->arena[process->pc];
	if (j >= 0x01 && j <= 0x10)
	{
		process->opcode = j;
		process->sleeper = g_op_tab[j - 1].cycle - 1;
		return (1);
	}
	return (0);
}

int			check_coding_param(int *tab, unsigned char opcode)
{
	unsigned int	i;
	unsigned char	j;

	i = 0;
	j = opcode - 1;
	while (i < g_op_tab[j].n_arg)
	{
		if ((g_op_tab[j].type[i] & tab[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	fill_coding_param(t_env *env, unsigned char coding_octet,
							char arg_type, t_process *process)
{
	int i;

	i = env->exception;
	if ((coding_octet & (1u << arg_type))
			&& !(coding_octet & (1u << (arg_type - 1))))
	{
		process->args_type[i] = T_DIR;
		if (g_op_tab[process->opcode - 1].size_dir == 0)
			process->args_size[i] = DIR_SIZE;
		else
			process->args_size[i] = IND_SIZE;
	}
	else if (!(coding_octet & (1u << arg_type))
			&& (coding_octet & (1u << (arg_type - 1))))
	{
		process->args_type[i] = T_REG;
		process->args_size[i] = 1;
	}
	else
	{
		process->args_type[i] = 0;
		process->args_size[i] = 0;
	}
}

t_process	*scan_coding_param(t_process *process, t_env *env)
{
	unsigned int	i;
	char			arg_type;
	unsigned char	coding_octet;

	i = 0;
	arg_type = 7;
	coding_octet = env->arena[(process->pc + 1) % MEM_SIZE];
	while (i < g_op_tab[process->opcode - 1].n_arg)
	{
		if ((coding_octet & (1u << arg_type))
				&& (coding_octet & (1u << (arg_type - 1))))
		{
			process->args_type[i] = T_IND;
			process->args_size[i] = IND_SIZE;
		}
		else
		{
			env->exception = i;
			fill_coding_param(env, coding_octet, arg_type, process);
		}
		arg_type -= 2;
		i++;
	}
	return (process);
}
