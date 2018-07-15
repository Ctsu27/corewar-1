/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:40:29 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/25 10:56:51 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dasm.h"

static void	init_data(t_data *data)
{
	data->opcode = -1;
	data->octpc = -1;
	data->param = NULL;
	data->type = NULL;
}

static int	valid_param_size(t_data *data, int cur, int size_champ)
{
	int		size;
	int		n;

	size = 0;
	n = -1;
	while (++n < g_op_tab[data->opcode - 1].n_arg - 1)
		size = size + ope_size_type(data->type[n], data->opcode - 1);
	if (cur + (int)g_op_tab[data->opcode - 1].isopc + size >= size_champ)
		return (0);
	return (1);
}

static int	parsing_champion(t_env *e, int size_champ, unsigned char *buf)
{
	t_data	data;
	int		cur;

	if ((e->head = init_lst(NULL)) == NULL)
		ft_panic(1);
	cur = 0;
	while (cur < size_champ - 1)
	{
		init_data(&data);
		if ((data.opcode = buf[cur]) < 1 || data.opcode > 16)
			return (-1);
		if (alloc_data(&data) == -1)
			ft_last_resort(e->head);
		cat_lst(e, &data);
		if (g_op_tab[data.opcode - 1].isopc == true
				&& valid_opc(&data, (data.octpc = buf[cur + 1])) == 0)
			return (-1);
		else if (g_op_tab[data.opcode - 1].isopc == false)
			data.type[0] = dir;
		if (valid_param_size(&data, cur, size_champ - 1) == 0
				|| valid_param(&data, buf, &cur) == 0)
			return (-1);
	}
	return (0);
}

int			check_champion(t_env *e, int fd)
{
	int				ret;
	unsigned char	buf[e->header.prog_size + 1];

	if ((ret = read(fd, buf, e->header.prog_size + 1)) == -1)
	{
		ke_putstr("error: read\n");
		close(fd);
		return (-1);
	}
	if (ret < 3 || ret > CHAMP_MAX_SIZE
			|| (unsigned int)ret > e->header.prog_size)
	{
		ke_putstr("error: champion is corrupted\n");
		close(fd);
		return (-1);
	}
	if (parsing_champion(e, ret, buf) == -1)
	{
		ke_putstr("error: champion is corrupted\n");
		free_lst(e->head);
		close(fd);
		return (-1);
	}
	return (0);
}
