/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:45:47 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/05 21:32:21 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void					ft_corewar_winner(t_env *env)
{
	unsigned int	i;
	unsigned int	last_live;
	unsigned int	winner;
	int				number;

	i = 0;
	last_live = 0;
	winner = 0;
	ft_printf("Finish ! Number of cycles : %llu\n", env->cycles);
	while (i < env->nbr_players)
	{
		if (env->players[i].last_live > last_live)
		{
			last_live = env->players[i].last_live;
			winner = i;
			number = env->players[i].number;
		}
		i++;
	}
	ft_printf("{green}Contestant %d, \"%s\", has won !\n{eoc}",
			env->players[winner].number,
			env->players[winner].header.prog_name);
	exit(EXIT_SUCCESS);
}

static void				start_dump_game(t_env *env,
						char *waiting, unsigned int active_cycle)
{
	while (env->nbr_progs > 0)
	{
		while (active_cycle < env->cycle_to_die)
		{
			if (env->options & 1 && env->cycles == env->dump)
				break ;
			call_all_process(env);
			++active_cycle;
			++env->cycles;
			(env->options & 4) ? ft_printf("Cycle = %d\n", env->cycles) : 0;
			if (env->options & 2 && env->cycles % env->dump_repeat == 0)
			{
				display_arena(env);
				lo_get_next_line(1, &waiting);
				lo_strdel(&waiting);
			}
		}
		if (env->options & 1 && env->cycles == env->dump)
			break ;
		active_cycle = ft_check_all_process_life(env);
	}
	display_arena(env);
	if (env->nbr_progs == 0)
		ft_corewar_winner(env);
	exit(EXIT_SUCCESS);
}

void					start_game(t_env *env, unsigned int active_cycle)
{
	env->cycles = 0;
	(env->options & 3) ? start_dump_game(env, NULL, 0) : 0;
	while (env->nbr_progs > 0)
	{
		while (active_cycle < env->cycle_to_die)
		{
			call_all_process(env);
			(env->visu.active) ? v_rprint(env) : 0;
			(env->visu.active) ? ft_sleep(env) : 0;
			++active_cycle;
			++env->cycles;
			if (env->options & 4)
				ft_printf("Cycle = %d\n", env->cycles);
		}
		active_cycle = ft_check_all_process_life(env);
	}
	if (env->visu.active)
	{
		v_rprint(env);
		p_info(env, true);
	}
	else
		ft_corewar_winner(env);
}

void					call_all_process(t_env *env)
{
	t_list *process_list;

	process_list = env->progs;
	while (process_list)
	{
		call_process((t_process*)(process_list->content), env);
		process_list = process_list->next;
	}
}

void					call_process(t_process *process, t_env *env)
{
	if (process->sleeper == -1)
	{
		if (scan_opcode(process, env) == 0)
			process->pc = (process->pc + 1) % MEM_SIZE;
	}
	if (process->sleeper > 0)
		process->sleeper -= 1;
	else if (process->sleeper == 0)
		exec_instruction(process, env);
}
