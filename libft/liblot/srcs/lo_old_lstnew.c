/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_old_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:29:59 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:50 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*lo_lstnew(void const *content, size_t content_size)
{
	t_list*ptr;

	if (!(ptr = (t_list *)lo_memalloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		ptr->content = NULL;
	}
	else
	{
		if (!(ptr->content = lo_memalloc(content_size)))
			return (NULL);
		ptr->content = lo_memmove(ptr->content, content, content_size);
	}
	ptr->next = NULL;
	return (ptr);
}
