/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:52:39 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/07 13:57:17 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			exec_instruction(t_process *process, t_env *env)
{
	static void	(*operation_functions[16])(t_process*, t_env*) = {&ft_live,
				&ft_ld, &ft_st, &ft_add_op, &ft_sub_op,
				&ft_and_op, &ft_or_op, &ft_xor_op, &ft_zjmp, &ft_ldi_op,
				&ft_sti_op, &ft_fork_op, &ft_lld_op, &ft_lldi_op,
				&ft_lfork_op, &ft_aff_op};

	operation_functions[process->opcode - 1](process, env);
	process->sleeper = -1;
	process->opcode = 0;
}
