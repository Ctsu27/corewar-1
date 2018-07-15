/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:41:41 by ndelest           #+#    #+#             */
/*   Updated: 2018/07/07 16:32:31 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_duplicate(t_env *env)
{
	unsigned int j;

	if (env->nbr_live >= MAX_PLAYERS)
	{
		ft_printf("Usage : Invalid number of players.\n");
		exit(EXIT_SUCCESS);
	}
	j = 0;
	while (j < env->nbr_live)
	{
		if (j >= MAX_PLAYERS)
		{
			ft_printf("Usage : Invalid number of players.\n");
			exit(EXIT_SUCCESS);
		}
		if (env->players[j].number == env->players[env->nbr_live].number)
			return (1);
		j++;
	}
	return (0);
}

void	champ_name(char **av, int ac, t_env *env, int i)
{
	if (env->nbr_live + 1 > env->nbr_players)
	{
		ft_printf("Option '-n' isn't linked to a player.\n");
		exit(EXIT_SUCCESS);
	}
	if (i < ac && lo_is_integer(av[i]) == 1)
	{
		env->players[env->nbr_live].number = lo_atoi(av[i]);
		if (check_duplicate(env) == 1)
		{
			ft_printf("Duplicate player number.\n");
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		ft_printf("Invalid player number.\n");
		exit(EXIT_SUCCESS);
	}
}

void	dump_repeat(char **av, int ac, t_env *env, int *i)
{
	if (*i + 1 < ac && lo_is_integer(av[*i + 1]) == 1)
	{
		if (av[*i + 1][0] == '-')
		{
			ft_printf("Positiv dump value is needed for option '-dr'.\n");
			exit(EXIT_SUCCESS);
		}
		env->dump_repeat = (unsigned int)lo_atoi_unsignedlong(av[*i + 1]);
		if (!(env->options & 2))
			(env->options) += 2;
		*i += 1;
	}
	else if (*i + 1 >= ac)
	{
		ft_printf("Option '-dr' need a cycle to dump.\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Invalid cycle to dump.\n");
		exit(EXIT_SUCCESS);
	}
}

void	dump_timing(char **av, int ac, t_env *env, int *i)
{
	if (*i + 1 < ac && lo_is_integer(av[*i + 1]) == 1)
	{
		if (av[*i + 1][0] == '-')
		{
			ft_printf("Positiv dump value is needed for option '-d'.\n");
			exit(EXIT_SUCCESS);
		}
		env->dump = (unsigned int)lo_atoi_unsignedlong(av[*i + 1]);
		if (!(env->options & 1))
			++(env->options);
		*i += 1;
	}
	else if (*i + 1 >= ac)
	{
		ft_printf("Option '-d' need a cycle to dump.\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Invalid cycle to dump.\n");
		exit(EXIT_SUCCESS);
	}
}
