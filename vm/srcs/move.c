/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:45:56 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/23 21:26:35 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_write_arena(unsigned char *line, unsigned int index,
				unsigned int octet, unsigned int number)
{
	while (octet > 0)
	{
		index = index % MEM_SIZE;
		line[index] = (unsigned char)(number >> (octet - 1) * 8);
		--octet;
		++index;
	}
}

unsigned int	ft_read_arena(unsigned char *line,
				unsigned int index, unsigned int octet)
{
	unsigned int	number;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	number = 0;
	x = 0;
	while (i < octet)
	{
		index = (index + x) % MEM_SIZE;
		number = (number << 8) + line[index];
		++i;
		x == 0 ? x = 1 : 0;
	}
	return (number);
}

void			move_process(t_process *process, t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	t_op			operation;
	unsigned int	pc_start;

	operation = g_op_tab[process->opcode - 1];
	j = 0;
	i = 1 + (operation.isopc * env->nbr_args);
	pc_start = process->pc;
	while (j < operation.n_arg)
		i = i + (unsigned int)process->args_size[j++];
	process->pc = (process->pc + i) % MEM_SIZE;
	if (env->options & 32)
	{
		ft_printf("ADV %d (%#0.4x -> %#0.4x)", i, pc_start, process->pc);
		while (pc_start != process->pc)
		{
			ft_printf(" %0.2x", env->arena[pc_start]);
			pc_start = (pc_start + 1) % MEM_SIZE;
		}
		write(1, "\n", 1);
	}
}

void			ft_sleep(t_env *env)
{
	if (env->visu.speed == 0)
		usleep(150000);
	else if (env->visu.speed == 1)
		usleep(15000);
	else if (env->visu.speed == 2)
		usleep(1500);
}
