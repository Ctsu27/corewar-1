/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_name.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 20:05:20 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/21 14:11:00 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static inline void		set_n1(t_env *env)
{
	size_t				len;

	len = (size_t)lo_strlen(env->players[0].header.prog_name);
	lo_bzero(env->visu.p_name[0], 23);
	if (len < 22)
		lo_strncpy(env->visu.p_name[0], env->players[0].header.prog_name, len);
	else
	{
		lo_strncpy(env->visu.p_name[0], env->players[0].header.prog_name, 20);
		env->visu.p_name[0][19] = '.';
		env->visu.p_name[0][20] = '.';
		env->visu.p_name[0][21] = '.';
		env->visu.p_name[0][22] = '\0';
	}
}

static inline void		set_n2(t_env *env)
{
	size_t				len;

	len = (size_t)lo_strlen(env->players[1].header.prog_name);
	lo_bzero(env->visu.p_name[1], 23);
	if (len < 22)
		lo_strncpy(env->visu.p_name[1], env->players[1].header.prog_name, len);
	else
	{
		lo_strncpy(env->visu.p_name[1], env->players[1].header.prog_name, 20);
		env->visu.p_name[1][19] = '.';
		env->visu.p_name[1][20] = '.';
		env->visu.p_name[1][21] = '.';
		env->visu.p_name[1][22] = '\0';
	}
}

static inline void		set_n3(t_env *env)
{
	size_t				len;

	len = (size_t)lo_strlen(env->players[2].header.prog_name);
	lo_bzero(env->visu.p_name[2], 23);
	if (len < 22)
		lo_strncpy(env->visu.p_name[2], env->players[2].header.prog_name, len);
	else
	{
		lo_strncpy(env->visu.p_name[2], env->players[2].header.prog_name, 20);
		env->visu.p_name[2][19] = '.';
		env->visu.p_name[2][20] = '.';
		env->visu.p_name[2][21] = '.';
		env->visu.p_name[2][22] = '\0';
	}
}

static inline void		set_n4(t_env *env)
{
	size_t				len;

	len = (size_t)lo_strlen(env->players[3].header.prog_name);
	lo_bzero(env->visu.p_name[3], 23);
	if (len < 22)
		lo_strncpy(env->visu.p_name[3], env->players[3].header.prog_name, len);
	else
	{
		lo_strncpy(env->visu.p_name[3], env->players[3].header.prog_name, 20);
		env->visu.p_name[3][19] = '.';
		env->visu.p_name[3][20] = '.';
		env->visu.p_name[3][21] = '.';
		env->visu.p_name[3][22] = '\0';
	}
}

void					v_name(t_env *env)
{
	set_n1(env);
	if (env->nbr_players > 1)
		set_n2(env);
	if (env->nbr_players > 2)
		set_n3(env);
	if (env->nbr_players > 3)
		set_n4(env);
}
