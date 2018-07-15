/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:21:41 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/05 19:27:25 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		corewar_usage(void)
{
	ft_printf("Usage ./corewar [ flags... ] Files.cor\n\n"
			"Usage flags: \n"
			"  -d [ cycle number... ] :: Dump memory and "
			"stop at a certain cycle\n"
			"  -n [ Name Number... ] :: Change a champion's number\n"
			"  -dr [ cycle number... ] :: Dump memory every N cycle\n"
			"  -g :: Active the visualizer, uncompatible with all other flag\n"
			"  -v [ 1 - 5 ] :: 1 - Cycle / 2 - Live /"
			"3 - Death / 4 - Moves / 5 - Display aff\n");
	return (-1);
}

int		main(int argc, char **argv)
{
	t_env env;

	if (argc < 2)
		return (corewar_usage());
	env = initialize_env();
	prepare_game(&env, argc, argv);
	if (env.visu.active)
	{
		v_main(&env);
		p_arena(&env, (MEM_SIZE / 64), NULL);
		p_info(&env, false);
		p_player(&env);
	}
	start_game(&env, (unsigned int)0);
	return (0);
}
