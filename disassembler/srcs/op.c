/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:19:46 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:25:10 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_op.h"
#include "op.h"
#include "libft.h"

t_op	g_op_tab[17] = {
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, 0},
	{NULL, 0, {0, 0, 0}, 0, 0, NULL, 0, 0}
};

int		ope_index(char *ope, int size)
{
	int			i;

	i = 0;
	if (ope == NULL || (size < 2 || size > 5))
		return (16);
	while (g_op_tab[i].ope != NULL
			&& ke_strncmp(g_op_tab[i].ope, ope, size) != 0)
		i++;
	return (i);
}

int		ope_dir_size(int index_ope)
{
	if (g_op_tab[index_ope].size2_dir == true)
		return (2);
	return (4);
}

t_bool	valid_type_from_ope(t_type type, int i_ope, int index_type)
{
	int		code_type;

	code_type = (type == indir) ? 4 : type;
	if ((code_type & g_op_tab[i_ope].type[index_type]) == 0)
		return (false);
	return (true);
}

int		ope_size_type(t_type type, int opcode)
{
	if (type == reg)
		return (1);
	else if (type == indir)
		return (2);
	return (ope_dir_size(opcode));
}
