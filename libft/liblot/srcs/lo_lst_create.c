/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_lst_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:59:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/06/22 18:11:45 by clrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*lo_create_lst(int size, int content_size)
{
	t_list	*start;
	t_list	*curr;
	t_list	*prev;

	if (!(start = lo_lst_new((size_t)content_size)))
		return (NULL);
	curr = start;
	prev = NULL;
	while (size > 1)
	{
		if (!(curr->next = lo_lst_new((size_t)content_size)))
			return (NULL);
		curr->prev = prev;
		prev = curr;
		curr = curr->next;
		--size;
	}
	curr->prev = prev;
	return (start);
}
