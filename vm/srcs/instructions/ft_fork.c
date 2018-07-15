/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:28:25 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/29 12:34:47 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_fork_op(t_process *process, t_env *env)
{
	int				index;
	t_list			*new_process;
	unsigned int	i;

	i = 0;
	process->args_type[0] = T_DIR;
	get_instruction_value(process, env);
	index = process->args_value[0];
	new_process = create_player(process->player, env);
	((t_process *)new_process->content)->carry = process->carry;
	((t_process *)new_process->content)->live = process->live;
	((t_process *)new_process->content)->pc = (unsigned int)(process->pc
		+ (index % IDX_MOD)) % MEM_SIZE;
	((t_process *)new_process->content)->sleeper = -1;
	while (i < REG_NUMBER)
	{
		((t_process *)new_process->content)->reg_tab[i] = process->reg_tab[i];
		i++;
	}
	++(env->nbr_progs);
	lo_lst_add(&env->progs, new_process);
	move_process(process, env);
}

void	ft_lfork_op(t_process *process, t_env *env)
{
	int				index;
	t_list			*new_process;
	unsigned int	i;

	i = 0;
	process->args_type[0] = T_DIR;
	get_instruction_value(process, env);
	index = process->args_value[0];
	new_process = create_player(process->player, env);
	((t_process *)new_process->content)->carry = process->carry;
	((t_process *)new_process->content)->live = process->live;
	((t_process *)new_process->content)->pc = (unsigned int)(process->pc
		+ index) % MEM_SIZE;
	((t_process *)new_process->content)->sleeper = -1;
	while (i < REG_NUMBER)
	{
		((t_process *)new_process->content)->reg_tab[i] = process->reg_tab[i];
		i++;
	}
	++(env->nbr_progs);
	lo_lst_add(&env->progs, new_process);
	move_process(process, env);
}
