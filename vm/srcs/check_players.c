/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 19:42:26 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/07 14:46:12 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	introduce_players(t_env *env)
{
	unsigned int	i;
	t_header		*title;

	i = 0;
	lo_putstr("Introducing contestants...\n");
	while (i < env->nbr_players)
	{
		title = &(env->players[i]).header;
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
			env->players[i].number, title->prog_size,
				title->prog_name, title->comment);
		i++;
		title = NULL;
	}
}
