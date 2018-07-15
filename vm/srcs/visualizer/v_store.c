/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_store.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:56:26 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/29 11:38:02 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			v_store(size_t pos, t_env *env, int ply, size_t len)
{
	size_t		i;

	i = 0;
	if (ply < 0)
		ply = -ply;
	pos = (pos + i) % MEM_SIZE;
	while (i < len)
	{
		if ((pos + i) < MEM_SIZE)
		{
			env->visu.slots[pos + i].active = true;
			env->visu.slots[pos + i].timer = 255;
			env->visu.slots[pos + i].color = (unsigned char)ply;
		}
		i++;
	}
}

void			v_clean(t_env *env)
{
	(env->visu.info) ? delwin(env->visu.info) : 0;
	(env->visu.arena) ? delwin(env->visu.arena) : 0;
	(env->visu.ply1) ? delwin(env->visu.ply1) : 0;
	(env->visu.ply2) ? delwin(env->visu.ply2) : 0;
	(env->visu.ply3) ? delwin(env->visu.ply3) : 0;
	(env->visu.ply4) ? delwin(env->visu.ply4) : 0;
	(env->visu.finish) ? delwin(env->visu.finish) : 0;
	endwin();
}
