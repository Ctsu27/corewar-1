/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:55:26 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/22 14:01:22 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dasm.h"

int		alloc_data(t_data *data)
{
	int		i;

	if ((data->type = (t_type *)malloc(sizeof(t_type)
					* g_op_tab[data->opcode - 1].n_arg)) == NULL)
		return (-1);
	if ((data->param = (unsigned int *)malloc(sizeof(unsigned int)
					* g_op_tab[data->opcode - 1].n_arg)) == NULL)
	{
		if (data->type != NULL)
			free(data->type);
		return (-1);
	}
	i = 0;
	while (i < g_op_tab[data->opcode - 1].n_arg)
	{
		data->type[i] = none;
		data->param[i] = (unsigned int)0;
		i++;
	}
	return (0);
}
