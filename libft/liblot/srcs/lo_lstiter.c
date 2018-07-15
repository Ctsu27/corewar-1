/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:57:17 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:48 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	lo_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!(f) || !(lst))
		return ;
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
