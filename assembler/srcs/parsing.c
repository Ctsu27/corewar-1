/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:32:08 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/05 21:27:47 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "ke_get_next_line.h"
#include "asm.h"

static void	check_assembler_fmt(t_env *e,
		char *line, char isname, unsigned int len)
{
	char	*start;
	char	*end;
	char	*rift;
	char	*tmp;

	end = ke_strchr(line, '\"');
	tmp = end;
	start = line + ke_strlen((isname == 0) ? COMMENT_CMD_STRING
			: NAME_CMD_STRING);
	rift = ke_strrchr(line, '\"');
	if (isname == 0 && rift - 1 - end > len)
		ft_exit_msg(e, "Champion comment too long (Max length 2048)\n");
	else if (isname == 1 && rift - 1 - end > len)
		ft_exit_msg(e, "Champion name too long (Max length 128)\n");
	if (line[ke_strlen(line) - 1] != '\"')
		ft_exit_msg(e, "Syntax error on cmd\n");
	while (--end >= start)
		if (*end != ' ' && *end != '\t' && *end != '\n')
			ft_exit_msg(e, "Syntax error on cmd\n");
	ke_strncpy((isname == 0) ? e->header.comment : e->header.prog_name,
			tmp + 1, ke_strlen(tmp + 1) - 1);
}

static int	treat_header(t_env *e, char *line)
{
	char	*tmp;

	if ((e->got_name == false || e->got_comment == false)
			&& (ke_strclen(line, '\"') != 2))
		ft_exit_msg(e, "Syntax error on cmd\n");
	tmp = ke_strchr(line, '\"');
	if (e->got_name == false && ke_strstr(line, NAME_CMD_STRING) == line)
	{
		check_assembler_fmt(e, line, (char)1, PROG_NAME_LENGTH);
		e->got_name = true;
	}
	else if (e->got_comment == false
			&& ke_strstr(line, COMMENT_CMD_STRING) == line)
	{
		check_assembler_fmt(e, line, (char)0, COMMENT_LENGTH);
		e->got_comment = true;
	}
	else
		return (-1);
	return (0);
}

static int	parse_line(t_env *e, char *line)
{
	t_bool	to_treat_header;

	to_treat_header = (e->got_name == false || e->got_comment == false);
	if (to_treat_header == true)
		if (treat_header(e, line) == -1)
			return (-1);
	if (to_treat_header == false)
		if (treat_champion(e, line) == -1)
			return (-1);
	return (0);
}

char		*take_good_line(char *line)
{
	char	*dest;
	char	*com_pos;
	char	*tmp;

	if (line == NULL)
		return (NULL);
	dest = line;
	tmp = line;
	if ((com_pos = ke_strchr(line, COMMENT_CHAR)) != NULL)
		if ((tmp = ke_strndup(line, (unsigned int)(com_pos - line))) == NULL)
			return (NULL);
	if ((dest = ke_strtrim(tmp)) == NULL)
		return (NULL);
	if (tmp != line)
		ke_strdel(&tmp);
	return (dest);
}

int			asm_parse(t_env *e, char *arg)
{
	int		fd;
	int		ret;
	char	*line;
	char	*ltreat;
	char	*dump;

	if ((fd = open(arg, O_RDONLY)) == -1)
		return (ft_error_msg(-1, "fail to open\n"));
	while ((ret = ke_get_next_line(fd, &line, &dump)) > 0)
	{
		if ((ltreat = take_good_line(line)) == NULL)
			ft_exit_msg(e, "malloc error\n");
		if (ltreat != NULL && ltreat[0] != '\0' && parse_line(e, ltreat) == -1)
		{
			if (ltreat != line)
				ke_strdel(&ltreat);
			ke_strdel(&line);
			ft_exit_msg(e, "error syntax\n");
		}
		if (ltreat != line)
			ke_strdel(&ltreat);
		ke_strdel(&line);
		e->y++;
	}
	return (asm_parsing_ret(e, ret));
}
