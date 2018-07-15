/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_finish.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:06:55 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/21 16:51:38 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void				ft_wait(t_env *env)
{
	env->visu.state = 9;
	refresh();
	while (env->visu.state == 9)
	{
		v_key(env);
		usleep(5);
	}
}

static unsigned int		get_winner(t_env *env)
{
	unsigned int		i;
	unsigned int		last_live;
	unsigned int		winner;

	i = 0;
	last_live = 0;
	winner = 0;
	while (i < env->nbr_players)
	{
		if (env->players[i].last_live > last_live)
		{
			last_live = env->players[i].last_live;
			winner = i;
		}
		i++;
	}
	return (winner);
}

static void				init_finish(t_env *env)
{
	env->visu.finish = newwin(32, 64, 23, 70);
	wbkgd(env->visu.finish, COLOR_PAIR(2));
	box(env->visu.finish, '&', 0);
	wrefresh(env->visu.finish);
}

static void				info_finish(t_env *env, unsigned int winner)
{
	int					len;
	int					n;

	len = lo_strlen(env->players[winner].header.prog_name);
	n = 30 - (len / 2);
	mvwprintw(env->visu.finish, 5, 22, "          o");
	mvwprintw(env->visu.finish, 6, 22, "       o^/|\\^o");
	mvwprintw(env->visu.finish, 7, 22, "    o_^|\\/*\\/|^_o");
	mvwprintw(env->visu.finish, 8, 22, "   o\\*`'.\\|/.'`*/o");
	mvwprintw(env->visu.finish, 9, 22, "    \\\\\\\\\\\\|//////");
	mvwprintw(env->visu.finish, 10, 22, "     {><><@><><}");
	mvwprintw(env->visu.finish, 11, 22, "     `---------`");
	mvwprintw(env->visu.finish, 15, 23, "** THE WINNER IS **");
	mvwprintw(env->visu.finish, 20, n, " \"%s\"",
			env->players[winner].header.prog_name);
	mvwprintw(env->visu.finish, 18, 25, "** Player %d **", (winner + 1));
}

void					p_finish(t_env *env)
{
	init_finish(env);
	info_finish(env, get_winner(env));
	wrefresh(env->visu.finish);
	ft_wait(env);
}
