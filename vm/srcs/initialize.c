/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:43:55 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/25 16:03:50 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		help_env(t_env *env)
{
	env->cycle_to_die = CYCLE_TO_DIE;
	env->last_cycle_to_die = CYCLE_TO_DIE;
	env->nbr_progs = 0;
	env->checks = 1;
	env->nbr_live = 0;
	env->nbr_players = 0;
	env->id = 0;
	env->options = 0;
	env->dump = 0;
}

t_env		initialize_env(void)
{
	t_env			env;
	int				i;
	unsigned int	j;

	i = 0;
	env.progs = NULL;
	env.cycles = 0;
	help_env(&env);
	env.player_number = -1;
	j = MAX_ARGS_NUMBER;
	env.nbr_args = ((j * 2) / 8);
	env.dump_repeat = 0;
	env.exception = 0;
	while (i < MAX_PLAYERS)
	{
		env.players[i].origin_code = NULL;
		env.players[i].number = (i + 1) * -1;
		env.players[i].last_live = 0;
		++i;
	}
	env.visu.active = false;
	return (env);
}

static void	ft_reset_process(t_process *process)
{
	int		i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		process->args_type[i] = 0;
		process->args_value[i] = 0;
		process->args_size[i++] = 0;
	}
}

void		add_process(t_process *process_father, int pc, t_env *env)
{
	int			i;
	t_list		*lst;
	t_process	*process;

	if (!(process = (t_process*)malloc(sizeof(t_process))))
		exit(EXIT_FAILURE);
	i = 0;
	process->carry = process_father->carry;
	process->pc = (unsigned int)pc;
	process->sleeper = -1;
	process->player = process_father->player;
	process->live = process_father->live;
	process->opcode = 0;
	ft_reset_process(process);
	while (i < REG_NUMBER)
	{
		process->reg_tab[i] = process_father->reg_tab[i];
		++i;
	}
	if (!(lst = lo_lst_new(0)))
		exit(EXIT_FAILURE);
	lst->content = process;
	lo_lst_add_end(&env->progs, lst);
}
