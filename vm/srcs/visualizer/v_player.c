/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:17:33 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/29 12:45:17 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static inline void		print_ply1(t_env *env, WINDOW *data)
{
	if (!data)
		return ;
	wattron(data, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(data, 2, 3, "** Player 1		");
	wattron(data, COLOR_PAIR(3) | A_BOLD);
	mvwprintw(data, 2, 17, "%s", env->visu.p_name[0]);
	wattroff(data, COLOR_PAIR(3) | A_BOLD);
	wattron(data, COLOR_PAIR(2));
	mvwprintw(data, 4, 3, "Last live                 -> %d",
			env->players[0].last_live);
	mvwprintw(data, 5, 3, "Lives in current period   -> %d",
			env->players[0].lives);
	wrefresh(data);
}

static inline void		print_ply2(t_env *env, WINDOW *data)
{
	if (!data)
		return ;
	wattron(data, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(data, 2, 3, "** Player 2		");
	wattron(data, COLOR_PAIR(5) | A_BOLD);
	mvwprintw(data, 2, 17, "%s", env->visu.p_name[1]);
	wattroff(data, COLOR_PAIR(5) | A_BOLD);
	wattron(data, COLOR_PAIR(2));
	mvwprintw(data, 4, 3, "Last live                 -> %d",
			env->players[1].last_live);
	mvwprintw(data, 5, 3, "Lives in current period   -> %d",
			env->players[1].lives);
	wrefresh(data);
}

static inline void		print_ply3(t_env *env, WINDOW *data)
{
	if (!data)
		return ;
	wattron(data, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(data, 2, 3, "** Player 3		");
	wattron(data, COLOR_PAIR(7) | A_BOLD);
	mvwprintw(data, 2, 17, "%s", env->visu.p_name[2]);
	wattroff(data, COLOR_PAIR(7) | A_BOLD);
	wattron(data, COLOR_PAIR(2));
	mvwprintw(data, 4, 3, "Last live                 -> %d",
			env->players[2].last_live);
	mvwprintw(data, 5, 3, "Lives in current period   -> %d",
			env->players[2].lives);
	wrefresh(data);
}

static inline void		print_ply4(t_env *env, WINDOW *data)
{
	if (!data)
		return ;
	wattron(data, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(data, 2, 3, "** Player 4		");
	wattron(data, COLOR_PAIR(9) | A_BOLD);
	mvwprintw(data, 2, 17, "%s", env->visu.p_name[3]);
	wattroff(data, COLOR_PAIR(9) | A_BOLD);
	wattron(data, COLOR_PAIR(2));
	mvwprintw(data, 4, 3, "Last live                 -> %d",
			env->players[3].last_live);
	mvwprintw(data, 5, 3, "Lives in current period   -> %d",
			env->players[3].lives);
	wrefresh(data);
}

void					p_player(t_env *env)
{
	print_ply1(env, env->visu.ply1);
	if (env->nbr_players > 1)
		print_ply2(env, env->visu.ply2);
	if (env->nbr_players > 2)
		print_ply3(env, env->visu.ply3);
	if (env->nbr_players > 3)
		print_ply4(env, env->visu.ply4);
}
