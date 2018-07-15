/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:42:50 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:19:31 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H
# include "struct_op.h"

extern t_op	g_op_tab[17];

int		dasm_check_file(t_env *e, int fd);
int		check_champion(t_env *e, int fd);

int		valid_param(t_data *data, unsigned char *buf, int *cur);
int		valid_opc(t_data *data, int octpc);

t_lst	*init_lst(t_data *data);
void	free_lst(t_lst *head);
void	cat_lst(t_env *e, t_data *data);
void	lst_print(t_env *e, int fd);

int		ope_index(char *ope, int size);
int		ope_dir_size(int index_ope);
t_bool	valid_type_from_ope(t_type type, int i_ope, int index_type);
int		ope_size_type(t_type type, int opcode);

int		alloc_data(t_data *data);

int		dump_prog_size(int fd, char error);

void	ft_panic(char opt);
void	ft_last_resort(t_lst *head);
#endif
