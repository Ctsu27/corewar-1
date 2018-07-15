/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_param_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:21:25 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/07 13:44:56 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static int			asm_atoi(unsigned int *result, char **line, char error)
{
	while (**line >= '0' && **line <= '9')
	{
		*result = (unsigned int)((*result * 10) + (**line - '0'));
		if (error == 1 && *result > REG_NUMBER)
			return (-1);
		*line = *line + 1;
	}
	if (*result == 0)
		return (-1);
	return (0);
}

static char			*init_param_label(t_data *data, int i, char *line)
{
	char	*tmp;

	if (ke_strchr(LABEL_CHARS, *(line + 1)) == NULL
			&& ke_strchr(LABEL_CHARS, *line) == NULL)
		return (NULL);
	if (*line == LABEL_CHAR)
		line++;
	tmp = line;
	while (*tmp != '\0' && ke_strchr(LABEL_CHARS, *tmp) != NULL)
		tmp++;
	if (tmp == line)
		return (NULL);
	if ((data->param_label[i] = ke_strndup(line, tmp - line)) == NULL)
		return (NULL);
	return (tmp);
}

static unsigned int	handle_negative_value(t_data *data, unsigned int result)
{
	unsigned int	val;

	val = (ope_dir_size(data->opcode) == 2) ? (unsigned int)0xffff
		: (unsigned int)0xffffffff;
	return ((unsigned int)(val - result + 1));
}

static int			take_dir_indir_value(t_data *data, int i_type,
		unsigned int *result, char **line)
{
	t_bool			neg;

	neg = false;
	if (**line == '-')
	{
		neg = true;
		*line = *line + 1;
	}
	if (**line >= '0' && **line <= '9')
	{
		asm_atoi(result, line, 0);
		if (neg == true)
			*result = handle_negative_value(data, *result);
	}
	else if (neg == false && **line == LABEL_CHAR)
	{
		data->is_label[i_type] = true;
		*line = init_param_label(data, i_type, *line);
	}
	else
		return (-1);
	return (0);
}

char				*take_value_param(t_data *data, int i_type,
		unsigned int *result, char *line)
{
	if (*line == LABEL_CHAR && *(line + 1) == '\0')
		return (NULL);
	if (data->is_label[i_type] == true)
		line = init_param_label(data, i_type, line);
	else if (data->type[i_type] == reg && *line >= '0' && *line <= '9')
	{
		if (asm_atoi(result, &line, 1) == -1)
			return (NULL);
	}
	else if (data->type[i_type] == dir || data->type[i_type] == indir)
	{
		if (take_dir_indir_value(data, i_type, result, &line) == -1)
			return (NULL);
	}
	else
		return (NULL);
	return (line);
}
