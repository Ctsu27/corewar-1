/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:44:53 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/05 16:14:36 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

int		check_type(t_env *e, t_data *data, int i, char *line)
{
	if ((data->type[i] = take_param_type(*line)) == none)
	{
		cat_lst(e, data);
		return (-1);
	}
	if (valid_type_from_ope(data->type[i], data->opcode, i) == false)
	{
		cat_lst(e, data);
		return (-1);
	}
	if (data->type[i] == label)
	{
		data->type[i] = indir;
		data->is_label[i] = true;
	}
	return (0);
}

int		check_param_error(t_env *e, t_data *data, int i, char **line)
{
	if (data->type[i] != indir && **line == '\0')
	{
		cat_lst(e, data);
		return (-1);
	}
	if ((*line = take_value_param(data, i, &data->param[i], *line)) == NULL)
	{
		cat_lst(e, data);
		return (-1);
	}
	return (0);
}

int		last_check_param_error(t_env *e, t_data *data, int i, char *line)
{
	if (i < g_op_tab[data->opcode].n_arg && *line != SEPARATOR_CHAR)
	{
		cat_lst(e, data);
		return (-1);
	}
	else if (i == g_op_tab[data->opcode].n_arg && *line != '\0')
	{
		cat_lst(e, data);
		return (-1);
	}
	return (0);
}
