/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:42:51 by lmeyre            #+#    #+#             */
/*   Updated: 2018/07/01 14:58:02 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		littl_check(t_env *env, unsigned int i)
{
	t_list *tmp;

	tmp = env->progs;
	while (tmp)
	{
		if (((t_process*)tmp->content)->pc == i)
			ft_printf("{red}");
		tmp = tmp->next;
	}
}

static int		ft_printhexa(int *j, int line)
{
	*j = 0;
	lo_putchar('\n');
	ft_printf("%#.4x : ", line * 64);
	++line;
	return (line);
}

void			display_arena(t_env *env)
{
	unsigned int	i;
	int				j;
	int				line;
	char			*str;

	j = 0;
	i = 0;
	line = 1;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		littl_check(env, i);
		if (!(str = traduction(env->arena[i])))
			exit(EXIT_FAILURE);
		lo_putstr(str);
		lo_strdel(&str);
		ft_printf("{eoc}");
		lo_putchar(' ');
		++j;
		if (j == 64 && line < 64)
			line = ft_printhexa(&j, line);
		++i;
	}
	lo_putchar('\n');
}
