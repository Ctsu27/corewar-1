/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 09:24:20 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/07 13:52:22 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dasm.h"

static void	stock_type(t_data *data, int *type)
{
	int		cur;

	cur = 0;
	while (cur < g_op_tab[data->opcode - 1].n_arg)
	{
		data->type[cur] = (type[cur] == T_IND) ? indir : type[cur];
		cur++;
	}
}

static void	stock_param_value(t_data *data, int n, unsigned char *buf, int cur)
{
	int		size;
	int		i;

	size = ope_size_type(data->type[n], data->opcode - 1);
	i = 0;
	while (i < size)
	{
		data->param[n] = (data->param[n]
				| (buf[cur + i] << ((size - i - 1) * 8)));
		i++;
	}
}

int			valid_opc(t_data *data, int octpc)
{
	static int	type[3];
	int			n;

	n = 0;
	while (n < MAX_ARGS_NUMBER - g_op_tab[data->opcode - 1].n_arg)
	{
		if ((octpc & 0b11) != 0)
			return (0);
		octpc = octpc >> 2;
		n++;
	}
	n = 0;
	while (n < g_op_tab[data->opcode - 1].n_arg)
	{
		if ((g_op_tab[data->opcode - 1].type[g_op_tab[data->opcode - 1].n_arg
					- n - 1] & octpc) == 0)
			return (0);
		type[g_op_tab[data->opcode - 1].n_arg - n - 1] = octpc & 0b11;
		octpc = octpc >> 2;
		n++;
	}
	stock_type(data, type);
	return (1);
}

int			valid_param(t_data *data, unsigned char *buf, int *cur)
{
	int		n;
	int		size;

	*cur = *cur + (int)g_op_tab[data->opcode - 1].isopc + 1;
	n = 0;
	while (n < g_op_tab[data->opcode - 1].n_arg)
	{
		size = ope_size_type(data->type[n], data->opcode - 1);
		if (data->type[n] == reg && (buf[*cur] <= 0 || buf[*cur] > REG_NUMBER))
			return (0);
		stock_param_value(data, n, buf, *cur);
		n++;
		*cur = *cur + size;
	}
	return (1);
}
