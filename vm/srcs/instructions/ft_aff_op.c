/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:34:23 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/23 15:31:13 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_aff_op(t_process *process, t_env *env)
{
	unsigned char	aff;

	scan_coding_param(process, env);
	if (check_coding_param(process->args_type,
		process->opcode) == 0)
	{
		move_process(process, env);
		return ;
	}
	get_instruction_value(process, env);
	aff = (unsigned char)(process->reg_tab[process->args_value[0] - 1] % 256);
	if (env->options & 64)
		write(1, &aff, 1);
	move_process(process, env);
}
