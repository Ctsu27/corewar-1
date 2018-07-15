/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 09:40:12 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:47 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*lo_lst_new(size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)lo_memalloc(sizeof(t_list))))
		return (NULL);
	if (content_size == 0)
		ptr->content = NULL;
	else if (!(ptr->content = lo_memalloc(content_size)))
		return (NULL);
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
