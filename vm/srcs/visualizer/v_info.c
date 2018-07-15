/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:17:37 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/29 13:00:21 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static char			*get_speed(int n)
{
	char			*s;

	if (!(s = lo_strnew(20)))
		return (NULL);
	if (n == 0)
		lo_strcpy(s, "Slow    ");
	if (n == 1)
		lo_strcpy(s, "Moderate");
	if (n == 2)
		lo_strcpy(s, "Quick    ");
	return (s);
}

static void			print_info(WINDOW *info, t_env *env)
{
	char			*speed;

	speed = get_speed(env->visu.speed);
	wattron(info, COLOR_PAIR(2));
	if (env->visu.state == 0)
		mvwprintw(info, 8, 5, "V.M State			.::.		%s",
				"Paused  ");
	else
		mvwprintw(info, 8, 5, "V.M State			.::.		%s",
				"Running");
	mvwprintw(info, 9, 5, "Cycle			.::.		%d", env->cycles);
	mvwprintw(info, 11, 5, "Cycle Speed		.::.		%s",
			speed);
	mvwprintw(info, 12, 5, "Cycle_to_die		.::.		%d",
			env->cycle_to_die);
	mvwprintw(info, 13, 5, "Cycle Delta		.::.		%d", CYCLE_DELTA);
	mvwprintw(info, 15, 5, "Process			.::.		%d", env->nbr_progs);
	mvwprintw(info, 16, 5, "Number of live		.::.		%d",
			env->nbr_live);
	mvwprintw(info, 17, 5, "Check Max Number		.::.		%d",
			env->checks);
	wrefresh(info);
	(speed) ? lo_strdel(&speed) : 0;
}

static void			print_title(WINDOW *info, int x)
{
	int				gap;
	char			*s;
	size_t			len;

	s = lo_strdup("** INFORMATION SECTION **");
	len = lo_strlen(s) / 2;
	gap = x / 2;
	gap -= (int)len;
	wattron(info, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(info, 2, gap, "%s", s);
	wattroff(info, COLOR_PAIR(2) | A_BOLD);
	(s) ? lo_strdel(&s) : 0;
	wrefresh(info);
}

void				p_info(t_env *env, bool end)
{
	print_title(env->visu.info, 60);
	if (!end)
		print_info(env->visu.info, env);
	else
		p_finish(env);
	wrefresh(env->visu.info);
}

void				v_info(t_env *env)
{
	env->visu.info = newwin(22, 60, 6, 205);
	wbkgd(env->visu.info, COLOR_PAIR(2));
	box(env->visu.info, 0, 0);
	wrefresh(env->visu.info);
}
