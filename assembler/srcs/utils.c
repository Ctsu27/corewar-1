/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:20:08 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/07 16:26:38 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

int		ft_error_msg(int ret, char const *str)
{
	ke_putstr(str);
	return (ret);
}

int		asm_parsing_ret(t_env *e, int ret)
{
	if (ret == -1)
		ft_exit_msg(e, "read error\n");
	if (e->got_name == false || e->got_comment == false)
		return (ft_error_msg(-1, "error: need commands -> name and comment\n"));
	if (e->head == NULL && e->tmp == NULL)
		return (ft_error_msg(-1, "error: empty champion\n"));
	if (e->head == NULL && e->tmp != NULL)
	{
		e->y = 0;
		ft_exit_msg(e, "error: empty champion\n");
	}
	return (0);
}

void	ft_exit_msg(t_env *e, char const *str)
{
	ke_putstr(str);
	if (ke_strcmp(str, "read error\n") != 0)
	{
		if (e->y > 0)
		{
			ke_putstr("line : ");
			ke_putnbr(e->y);
			ke_putstr("\n");
		}
	}
	if (e != NULL)
	{
		if (e->head != NULL)
			free_lst(e->head);
		if (e->tmp != NULL)
			free_lst_lbl(e->tmp);
	}
	exit(-1);
}

int		ft_octlen(unsigned int value)
{
	int		len;

	if (value == (unsigned int)0)
		return (1);
	len = 0;
	while (value != (unsigned int)0)
	{
		value = (value >> 8);
		len++;
	}
	return (len);
}
