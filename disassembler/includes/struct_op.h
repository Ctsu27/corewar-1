/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_op.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:36:58 by kehuang           #+#    #+#             */
/*   Updated: 2018/06/29 12:19:47 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_OP_H
# define STRUCT_OP_H
# include "op.h"

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef enum	e_type
{
	none = 0,
	reg = 1,
	dir = 2,
	indir = 3
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

typedef struct	s_data
{
	int				octpc;
	unsigned int	*param;
	t_type			*type;
	int				opcode;
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
}				t_env;

#endif
