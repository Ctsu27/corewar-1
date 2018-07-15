/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:38:46 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/25 16:03:42 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				prepare_game(t_env *env, int ac, char *av[])
{
	get_options(env, av, ac, 0);
	read_params(env, ac, av);
	lo_memset(env->arena, 0, MEM_SIZE);
	initialize_players(env);
	set_players(env, 0);
	introduce_players(env);
}

void				set_players(t_env *env, unsigned int place)
{
	unsigned int	space;
	unsigned int	player;
	unsigned int	i;
	unsigned int	j;
	t_list			*tmp;

	space = MEM_SIZE / env->nbr_players;
	player = 0;
	tmp = env->progs;
	while (tmp->next)
		tmp = tmp->next;
	while (player < env->nbr_players)
	{
		j = 0;
		i = place;
		env->players[player].start_position = place;
		((t_process *)(tmp->content))->pc = place;
		while (j < env->players[player].header.prog_size)
			env->arena[i++] = env->players[player].origin_code[j++];
		place = place + space;
		player++;
		tmp = tmp->prev;
	}
}

static void			fill_create_player(t_process *process,
					int player_nbr, t_env *env)
{
	process->carry = 0;
	process->pc = 0;
	process->sleeper = -1;
	process->player = player_nbr;
	process->live = 0;
	process->id = ++(env->id);
	process->opcode = 0;
}

t_list				*create_player(int player_nbr, t_env *env)
{
	int			i;
	t_process	*process;
	t_list		*lst;

	i = 0;
	if (!(process = (t_process*)malloc(sizeof(t_process))))
		exit(EXIT_FAILURE);
	if (!(lst = lo_lst_new(0)))
		exit(EXIT_FAILURE);
	fill_create_player(process, player_nbr, env);
	while (i < MAX_ARGS_NUMBER)
	{
		process->args_type[i] = 0;
		process->args_value[i] = 0;
		process->args_size[i++] = 0;
	}
	i = 0;
	while (i < REG_NUMBER)
		process->reg_tab[i++] = 0;
	process->reg_tab[0] = player_nbr;
	lst->content = process;
	return (lst);
}

void				initialize_players(t_env *env)
{
	unsigned int	j;

	if (env->nbr_players == 0)
		return ;
	j = 0;
	env->nbr_progs = env->nbr_players;
	env->progs = create_player(env->players[j++].number, env);
	while (j < env->nbr_players)
	{
		env->players[j].last_live = 0;
		lo_lst_add(&env->progs, create_player(env->players[j++].number, env));
	}
}
