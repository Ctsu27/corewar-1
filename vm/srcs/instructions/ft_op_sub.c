/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:38:24 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:38:25 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_sub_op(t_process *process, t_env *env)
{
	int		*tab_value;

	scan_coding_param(process, env);
	if (!check_coding_param(process->args_type, process->opcode)
			|| !get_instruction_value(process, env))
	{
		move_process(process, env);
		return ;
	}
	tab_value = process->args_value;
	process->reg_tab[tab_value[2] - 1] = process->reg_tab[tab_value[0] - 1]
		- process->reg_tab[tab_value[1] - 1];
	if (process->reg_tab[tab_value[2] - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
	move_process(process, env);
}
