/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_lst_push_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:20:01 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:47 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*lo_lst_push_params(int argc, char **argv)
{
	int		i;
	t_list	*start;

	if (argc < 2)
		return (NULL);
	i = 1;
	if (!(start = lo_lst_new(sizeof(argv[i]))))
		return (NULL);
	++i;
	while (i < argc)
	{
		lo_lst_add_end(&start, lo_lst_new(sizeof(argv[i])));
		++i;
	}
	return (start);
}
