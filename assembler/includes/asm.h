/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:39:13 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:05:11 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "struct_op.h"

int				assembler(t_env *e, char **argv);
int				asm_parse(t_env *e, char *arg);

int				treat_champion(t_env *e, char *line);
char			*take_value_param(t_data *data, int i_type,
		unsigned int *result, char *line);

int				check_type(t_env *e, t_data *data, int i, char *line);
int				check_param_error(t_env *e, t_data *data, int i, char **line);
int				last_check_param_error(t_env *e, t_data *data,
		int i, char *line);

int				ope_index(char *ope, int size);
int				ope_dir_size(int index_ope);
t_bool			valid_type_from_ope(t_type type, int i_ope, int index_type);
int				ope_size_type(t_type type, int opcode);
t_type			take_param_type(char letter);

t_lst			*init_lst(t_data *data);
void			cat_lst(t_env *e, t_data *data);
void			free_lst(t_lst *head);
void			print_lst_fd(t_lst *head, int fd);

t_lst_lbl		*init_lst_lbl(char *label_name);
void			cat_lst_lbl(t_env *e, char *label_name);
void			free_lst_lbl(t_lst_lbl *head);
void			print_lst_lbl(t_lst_lbl *head);

unsigned int	take_octpc(t_type *type, char n_arg);
void			jump_whitespace(char **str);

void			ft_exit_msg(t_env *e, char const *str);
int				ft_error_msg(int ret, char const *str);
int				asm_parsing_ret(t_env *e, int ret);
int				ft_octlen(unsigned int value);

int				label_check(t_env *e);
int				check_label_dump(t_env *e, t_lst *root, int addr, int index);
int				jump_addr(t_lst *i);
unsigned int	take_lbl_address_value(t_lst *root, int addr,
		int lab_addr, int i);
t_bool			last_label_finded(t_env *e, char *root_label);

#endif
