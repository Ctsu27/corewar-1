/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 20:05:18 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/29 10:56:10 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int			ft_check_cycles(t_env *env)
{
	unsigned int	i;

	i = 0;
	if (env->nbr_live >= NBR_LIVE)
	{
		if (env->cycle_to_die < CYCLE_DELTA)
			env->cycle_to_die = 0;
		else
			env->cycle_to_die = env->cycle_to_die - CYCLE_DELTA;
		env->checks = 1;
	}
	else if (env->checks == MAX_CHECKS)
	{
		if (env->cycle_to_die < CYCLE_DELTA)
			env->cycle_to_die = 0;
		else
			env->cycle_to_die = env->cycle_to_die - CYCLE_DELTA;
		env->checks = 1;
	}
	else
		++(env->checks);
	env->nbr_live = 0;
	while (i < env->nbr_players)
		env->players[i++].lives = 0;
	return (0);
}

static void				fill_check_life(t_env *env, int position, t_list *curr)
{
	t_list *tmp;

	while (curr)
	{
		if (((t_process *)(curr)->content)->live == 0)
		{
			tmp = curr->next;
			if (env->options & 16)
				ft_printf("Process %d has not lived during CTD %d"
						" and has been destroyed at cycle %u\n",
						((t_process *)(curr)->content)->id,
						env->cycle_to_die, env->cycles);
			lo_lst_del_one(&(env->progs), position);
			--(env->nbr_progs);
			curr = tmp;
		}
		else
		{
			((t_process *)(curr)->content)->live = 0;
			curr = curr->next;
			++position;
		}
	}
}

unsigned int			ft_check_all_process_life(t_env *env)
{
	t_list			*curr;
	t_list			*tmp;
	int				position;

	curr = env->progs;
	while (curr && ((t_process *)(curr)->content)->live == 0)
	{
		tmp = curr->next;
		if (env->options & 16)
			ft_printf("Process %d has not lived during CTD %d"
					" and has been destroyed at cycle %u avec opcode %d\n",
					((t_process *)(curr)->content)->id,
					env->cycle_to_die, env->cycles);
		lo_lst_del_one(&(env->progs), 1);
		--(env->nbr_progs);
		curr = tmp;
	}
	if (env->progs == NULL)
		return (ft_check_cycles(env));
	((t_process *)(curr)->content)->live = 0;
	curr = curr->next;
	position = 2;
	fill_check_life(env, position, curr);
	return (ft_check_cycles(env));
}
