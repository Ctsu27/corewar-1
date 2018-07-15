/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:24:36 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/05 21:35:41 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include "op.h"

int		alloc_data(t_data *data)
{
	if (data == NULL)
		return (-1);
	if ((data->param = (unsigned int *)malloc(sizeof(unsigned int)
					* g_op_tab[data->opcode].n_arg)) == NULL)
		return (-1);
	if ((data->type = (t_type *)malloc(sizeof(t_type)
					* g_op_tab[data->opcode].n_arg)) == NULL)
		return (-1);
	if ((data->is_label = (t_bool *)malloc(sizeof(t_bool)
					* g_op_tab[data->opcode].n_arg)) == NULL)
		return (-1);
	return (0);
}

int		init_data(t_env *e, t_data *data, int i_ope)
{
	int		i;

	if (data == NULL || (e->head == NULL && (e->head = init_lst(NULL)) == NULL))
		return (-1);
	data->opcode = i_ope;
	data->y = e->y;
	data->octpc = 0;
	if (alloc_data(data) == -1)
		return (-1);
	i = -1;
	while (++i < g_op_tab[i_ope].n_arg)
	{
		data->param[i] = (unsigned int)0;
		data->type[i] = none;
		data->is_label[i] = false;
	}
	i = -1;
	while (++i < 3)
		data->param_label[i] = NULL;
	data->param_label[3] = 0;
	data->head_label = e->tmp;
	e->tmp = NULL;
	return (0);
}

int		asm_treat_operation(t_env *e, int i_ope, char *line)
{
	t_data	d;
	int		i;

	if (ke_strclen(line, SEPARATOR_CHAR) + 1 != g_op_tab[i_ope].n_arg)
		return (-1);
	if (init_data(e, &d, i_ope) == -1)
		ft_exit_msg(e, "Error on malloc\n");
	i = -1;
	while (++i < g_op_tab[i_ope].n_arg)
	{
		jump_whitespace(&line);
		if (check_type(e, &d, i, line) == -1)
			return (-1);
		if ((d.type[i] == indir && d.is_label[i] == true) || d.type[i] != indir)
			line++;
		if (check_param_error(e, &d, i, &line) == -1)
			return (-1);
		jump_whitespace(&line);
		if (last_check_param_error(e, &d, i + 1, line) == -1)
			return (-1);
		line++;
	}
	d.octpc = take_octpc(d.type, g_op_tab[d.opcode].n_arg);
	cat_lst(e, &d);
	return (0);
}

int		treat_label(t_env *e, char **line, char **tmp)
{
	if (e->tmp == NULL)
		e->tmp = init_lst_lbl(NULL);
	cat_lst_lbl(e, ke_strndup(*line, *tmp - *line));
	if (*(*(tmp) + 1) == '\0')
		return (0);
	else
		*line = *line + (*tmp - *line) + 1;
	jump_whitespace(line);
	*tmp = *line;
	while (ke_strchr(LABEL_CHARS, **tmp) != NULL)
		*tmp = *tmp + 1;
	return (1);
}

int		treat_champion(t_env *e, char *line)
{
	int			i_ope;
	char		*tmp;

	tmp = line;
	while (*tmp != '\0' && ke_strchr(LABEL_CHARS, *tmp) != NULL)
		tmp++;
	if (tmp == line)
		return (-1);
	if (*tmp == LABEL_CHAR)
		if (treat_label(e, &line, &tmp) == 0)
			return (0);
	if ((i_ope = ope_index(line, tmp - line)) < 16)
	{
		if (line[ke_strlen(g_op_tab[i_ope].ope)] != ' '
				&& line[ke_strlen(g_op_tab[i_ope].ope)] != '\t')
			return (-1);
		return (asm_treat_operation(e, i_ope,
					line + ke_strlen(g_op_tab[i_ope].ope) + 1));
	}
	if (i_ope == 16)
		return (-1);
	return (0);
}
