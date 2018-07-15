/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:38:35 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:38:37 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_xor_op(t_process *process, t_env *env)
{
	int		*tab_value;
	int		value1;
	int		value2;

	scan_coding_param(process, env);
	if (!check_coding_param(process->args_type, process->opcode)
			|| !get_instruction_value(process, env))
	{
		move_process(process, env);
		return ;
	}
	tab_value = process->args_value;
	value1 = ft_return_value(env, process, 0);
	value2 = ft_return_value(env, process, 1);
	process->reg_tab[tab_value[2] - 1] = value1 ^ value2;
	if (process->reg_tab[tab_value[2] - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
	move_process(process, env);
}
