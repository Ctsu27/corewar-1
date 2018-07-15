/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:15:13 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/01 14:17:21 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"
#include "asm.h"

static char		*take_file_name(char *path)
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
	if ((dest = ke_strjoin((dot_pos == NULL) ? path : tmp, ".cor")) == NULL)
		return (NULL);
	if (tmp != NULL)
		free(tmp);
	return (dest);
}

unsigned int	cw_take_size_champion(t_lst *head)
{
	t_lst			*i;
	int				index;
	unsigned int	size;
	unsigned int	oct;

	oct = 0;
	i = head;
	while (i != NULL)
	{
		index = 0;
		size = 1;
		if (i->data.param != NULL)
		{
			while (index < g_op_tab[i->data.opcode].n_arg)
			{
				size += ope_size_type(i->data.type[index], i->data.opcode);
				index++;
			}
			if (g_op_tab[i->data.opcode].isopc == true)
				size++;
			oct = oct + size;
		}
		i = i->next;
	}
	return (oct);
}

void			cw_print_champion(t_env *e, int fd)
{
	ke_putuchar_fd((unsigned char)((e->header.magic >> 24) & 0xff), fd);
	ke_putuchar_fd((unsigned char)((e->header.magic >> 16) & 0xff), fd);
	ke_putuchar_fd((unsigned char)((e->header.magic >> 8) & 0xff), fd);
	ke_putuchar_fd((unsigned char)(e->header.magic & 0xff), fd);
	write(fd, e->header.prog_name, PROG_NAME_LENGTH);
	ke_putuchar_fd((unsigned char)0, fd);
	ke_putuchar_fd((unsigned char)0, fd);
	ke_putuchar_fd((unsigned char)0, fd);
	ke_putuchar_fd((unsigned char)0, fd);
	ke_putuchar_fd((unsigned char)((e->header.prog_size >> 24) & 0xff), fd);
	ke_putuchar_fd((unsigned char)((e->header.prog_size >> 16) & 0xff), fd);
	ke_putuchar_fd((unsigned char)((e->header.prog_size >> 8) & 0xff), fd);
	ke_putuchar_fd((unsigned char)((e->header.prog_size) & 0xff), fd);
	write(fd, e->header.comment, COMMENT_LENGTH);
	ke_putuchar_fd((unsigned char)0, fd);
	ke_putuchar_fd((unsigned char)0, fd);
	ke_putuchar_fd((unsigned char)0, fd);
	ke_putuchar_fd((unsigned char)0, fd);
	if (e->head != NULL)
		print_lst_fd(e->head, fd);
	if (e->tmp != NULL)
		free_lst_lbl(e->tmp);
}

static int		checking_asm(t_env *e, char **file_name, char *src_name)
{
	if ((e->header.prog_size = cw_take_size_champion(e->head)) > CHAMP_MAX_SIZE)
	{
		if (e->head != NULL)
			free_lst(e->head);
		ke_putstr("Champion too big: actuel size (");
		ke_putnbr(e->header.prog_size);
		ke_putstr(") max (");
		ke_putnbr(CHAMP_MAX_SIZE);
		ke_putstr(")\n");
		return (-1);
	}
	if ((*file_name = take_file_name(src_name)) == NULL)
	{
		if (e->head != NULL)
			free_lst(e->head);
		return (-1);
	}
	return (0);
}

int				assembler(t_env *e, char **argv)
{
	int		fd;
	char	*file_name;

	if (checking_asm(e, &file_name, argv[1]) == -1)
		return (-1);
	if ((fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		ke_putstr("fail to create ");
		ke_putstr(file_name);
		ke_putstr(" to write\n");
		exit(-1);
	}
	cw_print_champion(e, fd);
	close(fd);
	ke_putstr("Writing output program to ");
	ke_putstr(file_name);
	ke_putstr("\n");
	free(file_name);
	if (e->head != NULL)
		free_lst(e->head);
	return (0);
}
