/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <kehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:00:30 by kehuang           #+#    #+#             */
/*   Updated: 2018/07/07 13:27:43 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LO_GET_NEXT_LINE_H
# define LO_GET_NEXT_LINE_H
# define BUFF_SIZE 4096

# include "./libft.h"

typedef struct	s_fd
{
	struct s_fd	*next;
	char		*tmp;
	char		padding[4];
	int			fd;
}				t_fd;

typedef struct	s_filler
{
	int			ret;
	int			bool;
	int			boolbis;
	int			lll;
	char		*buf;
}				t_filler;

int				lo_get_next_line(int fd, char **line);

#endif
