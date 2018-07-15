/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_lst_del_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:22:34 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:45 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		lo_lst_del_all(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	while ((*lst)->next)
		*lst = (*lst)->next;
	while (*lst)
	{
		if ((*lst)->content)
			free((*lst)->content);
		(*lst)->content = NULL;
		if (!((*lst)->prev))
			break ;
		*lst = (*lst)->prev;
		free((*lst)->next);
	}
	free(*lst);
}
