/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:05:48 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/18 13:53:00 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static inline void			get_process(t_env *env)
{
	t_list				*tmp;
	t_process			*cnt;

	tmp = env->progs;
	cnt = NULL;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		cnt = tmp->content;
		env->visu.slots[cnt->pc].active = true;
		tmp = tmp->next;
	}
	cnt = tmp->content;
	env->visu.slots[cnt->pc].active = true;
}

static inline void			reset_process(t_env *env)
{
	int						i;

	i = 0;
	while (i < MEM_SIZE)
	{
		env->visu.slots[i].active = false;
		if (env->visu.slots[i].timer > 0)
			env->visu.slots[i].timer -= 1;
		i++;
	}
}

void						v_process(t_env *env)
{
	reset_process(env);
	get_process(env);
}
