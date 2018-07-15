/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:57:41 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/23 21:26:45 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		get_nbr_players(t_env *env, char **av, int ac)
{
	int i;

	i = 0;
	while (i < ac)
		if (detect_champion(av[i++]) == 1)
			++env->nbr_players;
}

int				detect_champion(char *str)
{
	int		i;
	int		len;

	if ((len = lo_strlen(str)) < 5)
		return (0);
	i = 0;
	while (str[i])
	{
		if (lo_is_whitespace(str[i]) == 1)
			return (0);
		++i;
	}
	return (lo_strcmp(&str[len - 4], ".cor") != 0 ? 0 : 1);
}

static void		fill_options(t_env *env, int *i, char **av, int ac)
{
	if (lo_strcmp(av[*i], "-v") == 0)
		verbosity(av, ac, env, i);
	else if (lo_strcmp(av[*i], "-dr") == 0)
		dump_repeat(av, ac, env, i);
	else if (lo_strcmp(av[*i], "-d") == 0)
		dump_timing(av, ac, env, i);
	else if (lo_strcmp(av[*i], "-g") == 0)
		env->visu.active = true;
	else
	{
		ft_printf("Argument %d is invalid.\n", *i);
		exit(EXIT_FAILURE);
	}
}

static void		detect_champ_fill(t_env *env, int *found)
{
	(found == 0) ? env->players[env->nbr_live].number = env->player_number : 0;
	while (check_duplicate(env) == 1)
	{
		--env->player_number;
		env->players[env->nbr_live].number = env->player_number;
	}
	found == 0 ? --env->player_number : 0;
	++env->nbr_live;
	found = 0;
}

void			get_options(t_env *env, char **av, int ac, int found)
{
	int i;

	i = 1;
	get_nbr_players(env, av, ac);
	while (i < ac)
	{
		if (detect_champion(av[i]) == 1)
			detect_champ_fill(env, &found);
		else if (lo_strcmp(av[i], "-n") == 0)
		{
			++i;
			champ_name(av, ac, env, i);
			found = 1;
			env->exception = 1;
		}
		else
			fill_options(env, &i, av, ac);
		++i;
	}
	if ((env->options > 0 || env->exception == 1) && env->visu.active)
	{
		ft_printf("Usage : Visualizer shouldn't be use with other options.\n");
		exit(EXIT_SUCCESS);
	}
	env->nbr_live = 0;
}
