/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clrichar <clrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 10:33:05 by clrichar          #+#    #+#             */
/*   Updated: 2018/06/29 11:36:47 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static inline void			to_one_cycle(t_env *env)
{
	if (env->visu.state == 0)
	{
		env->visu.state = 2;
		v_rprint(env);
	}
}

static inline void			chg_speed(int c, t_env *env)
{
	if (c == '[')
	{
		if (env->visu.speed > 0)
			env->visu.speed -= 1;
		p_info(env, false);
	}
	if (c == ']')
	{
		if (env->visu.speed < 3)
			env->visu.speed += 1;
		p_info(env, false);
	}
}

static inline void			m_key_a(int c, t_env *env)
{
	if (c == 27)
	{
		v_clean(env);
		exit(EXIT_SUCCESS);
	}
	if (c == ' ')
	{
		if (env->visu.state == 0)
			env->visu.state = 1;
		else if (env->visu.state == 1)
			env->visu.state = 0;
	}
	if (c == 's')
		to_one_cycle(env);
	if (c == '[')
		chg_speed(c, env);
	if (c == ']')
		chg_speed(c, env);
	if (c > 0 && env->visu.state == 9)
	{
		v_clean(env);
		exit(EXIT_SUCCESS);
	}
}

void						v_pause(t_env *env)
{
	while (env->visu.state == 0)
	{
		v_key(env);
		usleep(5);
		if (env->visu.state == 2)
		{
			env->visu.state = 0;
			break ;
		}
	}
}

void						v_key(t_env *env)
{
	int			c;

	while (true)
	{
		c = getch();
		if (c == ERR)
			break ;
		else
			m_key_a(c, env);
	}
}
