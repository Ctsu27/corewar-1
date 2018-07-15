/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_arena.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:48:08 by clrichar          #+#    #+#             */
/*   Updated: 2018/07/05 19:24:22 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static inline void	get_pcolor(t_env *env, int pos)
{
	wattroff(env->visu.arena, A_REVERSE | A_BOLD);
	if (env->visu.slots[pos].color == 1 && env->visu.slots[pos].timer < 1)
		wattron(env->visu.arena, COLOR_PAIR(3) | A_BOLD);
	if (env->visu.slots[pos].color == 1 && env->visu.slots[pos].timer > 0)
		wattron(env->visu.arena, COLOR_PAIR(13) | A_BOLD);
	if (env->visu.slots[pos].color == 2 && env->visu.slots[pos].timer < 1)
		wattron(env->visu.arena, COLOR_PAIR(5) | A_BOLD);
	if (env->visu.slots[pos].color == 2 && env->visu.slots[pos].timer > 0)
		wattron(env->visu.arena, COLOR_PAIR(15) | A_BOLD);
	if (env->visu.slots[pos].color == 3 && env->visu.slots[pos].timer < 1)
		wattron(env->visu.arena, COLOR_PAIR(7) | A_BOLD);
	if (env->visu.slots[pos].color == 3 && env->visu.slots[pos].timer > 0)
		wattron(env->visu.arena, COLOR_PAIR(17) | A_BOLD);
	if (env->visu.slots[pos].color == 4 && env->visu.slots[pos].timer < 1)
		wattron(env->visu.arena, COLOR_PAIR(9) | A_BOLD);
	if (env->visu.slots[pos].color == 4 && env->visu.slots[pos].timer > 0)
		wattron(env->visu.arena, COLOR_PAIR(19) | A_BOLD);
}

static inline void	get_color(t_env *env, int pos)
{
	wattroff(env->visu.arena, A_REVERSE | A_BOLD);
	if (env->visu.slots[pos].active == true
			&& env->visu.slots[pos].color < 1)
		wattron(env->visu.arena, COLOR_PAIR(12));
	else if (env->visu.slots[pos].active == true
			&& env->visu.slots[pos].color != 0)
	{
		if (env->visu.slots[pos].color == 1)
			wattron(env->visu.arena, COLOR_PAIR(4) | A_BOLD);
		else if (env->visu.slots[pos].color == 2)
			wattron(env->visu.arena, COLOR_PAIR(6) | A_BOLD);
		else if (env->visu.slots[pos].color == 3)
			wattron(env->visu.arena, COLOR_PAIR(8) | A_BOLD);
		else if (env->visu.slots[pos].color == 4)
			wattron(env->visu.arena, COLOR_PAIR(10) | A_BOLD);
	}
	if (env->visu.slots[pos].active == false
			&& env->visu.slots[pos].color == 0)
		wattron(env->visu.arena, COLOR_PAIR(11) | A_BOLD);
}

void				p_arena(t_env *env, int n, char *s)
{
	int				i;
	int				j;
	int				pos;

	i = 0;
	v_process(env);
	while (i < 64)
	{
		j = 0;
		while (j < n)
		{
			pos = (i * 64) + j;
			if (env->visu.slots[pos].timer > 0)
				env->visu.slots[pos].timer -= 1;
			get_pcolor(env, pos);
			get_color(env, pos);
			s = traduction(env->arena[pos]);
			mvwprintw(env->visu.arena, 2 + i, 4 + (j * 3), "%s", s);
			(s) ? lo_strdel(&s) : 0;
			j++;
		}
		i++;
	}
	wrefresh(env->visu.arena);
}

void				vinit_slot(t_win *env)
{
	int				i;

	i = 0;
	while (i < MEM_SIZE)
	{
		env->slots[i].color = 0;
		env->slots[i].timer = 0;
		env->slots[i].active = false;
		i++;
	}
}

void				v_arena(t_env *env)
{
	int			width;
	int			height;

	width = ((MEM_SIZE / 64) * 3) + 7;
	height = 64 + 4;
	env->visu.arena = newwin(height, width, 6, 3);
	wbkgd(env->visu.arena, COLOR_PAIR(2));
	box(env->visu.arena, 0, 0);
	wrefresh(env->visu.arena);
}
