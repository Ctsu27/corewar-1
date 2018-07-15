/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:56:07 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/22 16:34:14 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "dasm.h"

static char	*take_file_name(char *path)
{
	char	*name;
	char	*dest;
	char	*dot_pos;
	char	*tmp;

	name = ke_strrchr(path, '/');
	name = (name != NULL) ? name++ : path;
	dot_pos = ke_strrchr(name, '.');
	tmp = NULL;
	if (dot_pos != NULL && (tmp = ke_strndup(path, dot_pos - path)) == NULL)
		return (NULL);
	if ((dest = ke_strjoin((dot_pos == NULL) ? path : tmp, ".s")) == NULL)
		return (NULL);
	if (tmp != NULL)
		free(tmp);
	return (dest);
}

static void	output_env(t_env *e, char *path)
{
	int		fd;
	char	*file_name;

	if ((file_name = take_file_name(path)) == NULL)
	{
		free_lst(e->head);
		ft_panic(1);
	}
	if ((fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		free(file_name);
		free_lst(e->head);
		ft_panic(2);
	}
	lst_print(e, fd);
	ke_putstr("Writing output program to ");
	ke_putstr(file_name);
	ke_putstr("\n");
	free(file_name);
	close(fd);
}

int			main(int argc, char **argv)
{
	t_env	e;
	int		fd;

	if (argc != 2)
	{
		ke_putstr("usage: ./dasm <sourcefile.cor>\n");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_panic(2);
	e.head = NULL;
	e.header.magic = COREWAR_EXEC_MAGIC;
	e.header.prog_size = 0;
	ke_memset(e.header.prog_name, (int)'\0', (size_t)(PROG_NAME_LENGTH + 1));
	ke_memset(e.header.comment, (int)'\0', (size_t)(COMMENT_LENGTH + 1));
	if (dasm_check_file(&e, fd) == -1)
		return (-1);
	close(fd);
	output_env(&e, argv[1]);
	free_lst(e.head);
	return (0);
}
