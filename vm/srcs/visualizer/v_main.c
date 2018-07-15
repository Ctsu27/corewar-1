/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:04:23 by clrichar          #+#    #+#             */
/*   Updated: 2018/07/05 19:24:29 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static inline void		set_struct(t_win *data)
{
	data->state = 0;
	data->speed = 1;
	data->finish = NULL;
	data->arena = NULL;
	data->info = NULL;
	data->ply1 = NULL;
	data->ply2 = NULL;
	data->ply3 = NULL;
	data->ply4 = NULL;
	data->p_posy[0] = 29 + 1;
	data->p_posy[1] = 37 + 2;
	data->p_posy[2] = 45 + 3;
	data->p_posy[3] = 53 + 4;
	data->p_posx = 212;
	vinit_slot(data);
}

static inline void		set_color(void)
{
	start_color();
	init_pair(1, 8, 8);
	init_pair(2, 15, 0);
	init_pair(3, 27, 0);
	init_pair(4, 233, 27);
	init_pair(13, 87, 0);
	init_pair(5, 71, 0);
	init_pair(6, 233, 71);
	init_pair(15, 76, 0);
	init_pair(7, 91, 0);
	init_pair(8, 233, 91);
	init_pair(17, 5, 0);
	init_pair(9, 191, 0);
	init_pair(10, 233, 191);
	init_pair(19, 227, 0);
	init_pair(11, 8, 0);
	init_pair(12, 8, 8);
}

static inline void		v_player(t_win *data, size_t n)
{
	if (n >= 1)
		data->ply1 = newwin(8, 45, (int)data->p_posy[0], (int)data->p_posx);
	if (n >= 2)
		data->ply2 = newwin(8, 45, (int)data->p_posy[1], (int)data->p_posx);
	if (n >= 3)
		data->ply3 = newwin(8, 45, (int)data->p_posy[2], (int)data->p_posx);
	if (n >= 4)
		data->ply4 = newwin(8, 45, (int)data->p_posy[3], (int)data->p_posx);
	wbkgd(data->ply1, COLOR_PAIR(2));
	wbkgd(data->ply2, COLOR_PAIR(2));
	wbkgd(data->ply3, COLOR_PAIR(2));
	wbkgd(data->ply4, COLOR_PAIR(2));
	box(data->ply1, '&', 0);
	box(data->ply2, '&', 0);
	box(data->ply3, '&', 0);
	box(data->ply4, '&', 0);
	wrefresh(data->ply1);
	wrefresh(data->ply2);
	wrefresh(data->ply3);
	wrefresh(data->ply4);
}

void					v_rprint(t_env *env)
{
	if (env->visu.state != 0)
	{
		p_info(env, false);
		p_arena(env, (MEM_SIZE / 64), NULL);
		p_player(env);
		v_key(env);
	}
	else
	{
		p_info(env, false);
		v_pause(env);
	}
}

void					v_main(t_env *env)
{
	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	set_color();
	set_struct(&env->visu);
	bkgd(COLOR_PAIR(2));
	attron(A_BOLD);
	mvprintw(3, (((MEM_SIZE / 64) * 3) / 2) - 2, "** C O R E W A R **");
	attroff(A_BOLD);
	mvprintw((LINES - 3), 3, "Made By : ndelest, lmeyre, kehuang, clrichar;");
	refresh();
	v_name(env);
	v_pcolor(env);
	v_player(&env->visu, env->nbr_players);
	v_arena(env);
	v_info(env);
}
