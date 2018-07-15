/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:16:57 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/23 21:26:34 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_live(t_process *process, t_env *env)
{
	int				value;
	unsigned int	i;

	i = 0;
	value = (int)ft_read_arena(env->arena, process->pc + 1, DIR_SIZE);
	process->live = 1;
	++(env->nbr_live);
	while (i < env->nbr_players)
	{
		if (env->players[i].number == value)
		{
			if (env->options & 8)
				ft_printf("Player %d has made a live at cycle %d\n", i + 1,
						env->cycles);
			env->players[i].lives += 1;
			env->players[i].last_live = env->cycles;
		}
		++i;
	}
	process->args_size[0] = DIR_SIZE;
	move_process(process, env);
}
