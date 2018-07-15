/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbosity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:52:01 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/23 15:31:02 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	assign_verbo(char *str, t_env *env)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] - '0' == 1)
			env->options += (env->options & 4 ? 0 : 4);
		else if (str[i] - '0' == 2)
			env->options += (env->options & 8 ? 0 : 8);
		else if (str[i] - '0' == 3)
			env->options += (env->options & 16 ? 0 : 16);
		else if (str[i] - '0' == 4)
			env->options += (env->options & 32 ? 0 : 32);
		else if (str[i] - '0' == 5)
			env->options += (env->options & 64 ? 0 : 64);
		else
		{
			ft_printf("number '%c' is not a valid parameter for option '-v'\n",
					str[i]);
			exit(EXIT_SUCCESS);
		}
		++i;
	}
}

void		verbosity(char **av, int ac, t_env *env, int *i)
{
	if (*i + 1 < ac && lo_is_integer(av[*i + 1]) == 1)
	{
		if (av[*i + 1][0] == '-')
		{
			ft_printf("Positiv options are needed for '-v' option.\n");
			exit(EXIT_FAILURE);
		}
		assign_verbo(av[*i + 1], env);
		*i += 1;
	}
	else if (*i + 1 >= ac)
	{
		ft_printf("Option '-v' need parameters options.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Invalid parameters for options '-v'.\n");
		exit(EXIT_FAILURE);
	}
}
