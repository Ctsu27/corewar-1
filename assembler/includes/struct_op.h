/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_op.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:36:58 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/01 14:17:03 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_OP_H
# define STRUCT_OP_H
# include "op.h"

typedef enum	e_bool
{
	false = 0,
	true = 1,
}				t_bool;

typedef enum	e_type
{
	none = 0,
	reg = 1,
	dir = 2,
	indir = 3,
	label = 4
}				t_type;

typedef struct	s_op
{
	char			*ope;
	char			n_arg;
	int				type[3];
	char			index;
	int				cycle;
	char			*desc;
	t_bool			isopc;
	t_bool			size2_dir;
}				t_op;

typedef struct	s_lst_lbl
{
	char				*label_name;
	struct s_lst_lbl	*next;
}				t_lst_lbl;

typedef struct	s_data
{
	int				octpc;
	unsigned int	*param;
	t_type			*type;
	t_bool			*is_label;
	int				opcode;
	unsigned int	y;
	t_lst_lbl		*head_label;
	char			*param_label[MAX_ARGS_NUMBER];
}				t_data;

typedef struct	s_lst
{
	t_data			data;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_env
{
	t_lst			*head;
	t_header		header;
	t_lst_lbl		*tmp;
	t_bool			got_name;
	t_bool			got_comment;
	unsigned int	y;
}				t_env;

extern	t_op	g_op_tab[17];
#endif
