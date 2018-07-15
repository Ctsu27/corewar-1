/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:47:11 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:47:12 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_zjmp(t_process *process, t_env *env)
{
	process->args_type[0] = T_DIR;
	get_instruction_value(process, env);
	if (process->carry == 0)
	{
		move_process(process, env);
		return ;
	}
	process->pc = (unsigned int)(process->pc
				+ (process->args_value[0] % IDX_MOD)) % MEM_SIZE;
}
