/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_pcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:51:11 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/21 14:12:34 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void				get_ply_color(t_env *env, size_t i)
{
	unsigned int		space;
	size_t				n;
	size_t				j;

	space = MEM_SIZE / env->nbr_players;
	n = (size_t)lo_strlen((const char *)env->players[i].origin_code);
	env->visu.slots[space * i].color = (unsigned char)(i + 1);
	j = env->players[i].header.prog_size;
	while (j > 0)
	{
		env->visu.slots[(space * i) + j].color = (unsigned char)(i + 1);
		j--;
	}
}

void					v_pcolor(t_env *env)
{
	size_t				i;

	i = 0;
	while (i < env->nbr_players)
	{
		get_ply_color(env, i);
		i++;
	}
}
