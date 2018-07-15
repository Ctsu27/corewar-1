/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:40:06 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/07 16:21:26 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"

static int	asm_usage(void)
{
	ke_putstr("usage: ./asm <sourcefile.s>\n");
	return (-1);
}

static void	init_env(t_env *e)
{
	if (e != NULL)
	{
		e->head = NULL;
		e->header.magic = COREWAR_EXEC_MAGIC;
		e->header.prog_size = 0;
		e->got_name = false;
		e->got_comment = false;
		e->y = 1;
		ke_bzero(e->header.prog_name, PROG_NAME_LENGTH + 1);
		ke_bzero(e->header.comment, COMMENT_LENGTH + 1);
		e->tmp = NULL;
	}
	else
		exit(EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_env	e;
	int		ret;

	if (argc != 2)
		return (asm_usage());
	init_env(&e);
	if (asm_parse(&e, argv[1]) == -1)
		return (-1);
	if ((ret = label_check(&e)) == -1 && e.tmp != NULL)
	{
		if (e.head != NULL)
			free_lst(e.head);
		if (e.tmp != NULL)
			free_lst_lbl(e.tmp);
		return (-1);
	}
	else if (ret == -1 && e.tmp == NULL)
	{
		(e.head != NULL) ? free_lst(e.head) : 0;
		return (-1);
	}
	return (assembler(&e, argv));
}
